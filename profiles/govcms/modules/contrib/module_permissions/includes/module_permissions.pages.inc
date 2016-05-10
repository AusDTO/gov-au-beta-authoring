<?php

/**
 * @file
 * Common pages for the module.
 */

/**
 * Menu callback; provides managed module enable/disable interface.
 *
 * @ingroup forms
 *
 * @see system_modules()
 */
function module_permissions_managed_modules($form, $form_state = array()) {
  // Get current list of modules.
  $files = system_rebuild_module_data();

  // Remove hidden modules from display list.
  $visible_files = $files;
  $exclude_core = variable_get('module_permissions_exclude_core', 1);

  foreach ($visible_files as $filename => $file) {
    if (!empty($file->info['hidden'])) {
      unset($visible_files[$filename]);
    }
    // // Remove core modules from display list.
    if ($exclude_core == TRUE && $file->info['package'] == 'Core') {
      unset($visible_files[$filename]);
    }
  }

  // If list is empty, return and set a message.
  if (empty($visible_files)) {
    drupal_set_message(t('Managed module list is empty.'), 'warning');
    return $form;
  }

  uasort($visible_files, 'module_permissions_sort_modules_by_info_name');

  // Remove module permissions from list.
  unset($visible_files['module_permissions']);

  // Create module listing.
  $managed_modules = module_permissions_managed_modules_load();
  $form['modules'] = array('#tree' => TRUE);

  // Iterate through each of the modules and add to form.
  foreach ($visible_files as $filename => $module) {
    $form['modules'][$module->info['package']][$filename] = array(
      '#tree' => TRUE,
      'granted' => array(
        '#type' => 'checkbox',
        '#title' => t('Granted'),
        '#default_value' => isset($managed_modules[$filename]) ? 1 : 0,
      ),
      'name' => array(
        '#markup' => $module->info['name'],
      ),
      'version' => array(
        '#markup' => $module->info['version'],
      ),
      'description' => array(
        '#markup' => t('!description', array('!description' => $module->info['description'])),
      ),
    );
  }

  // Add basic information to the fieldsets.
  foreach (element_children($form['modules']) as $package) {
    $form['modules'][$package] += array(
      '#type' => 'fieldset',
      '#title' => t('!package', array('!package' => $package)),
      '#collapsible' => TRUE,
      '#theme' => 'module_permissions_managed_modules_list',
      '#header' => array(
        array(
          'data' => t('Granted'),
          'class' => array('checkbox'),
        ),
        t('Name'),
        t('Version'),
        t('Description'),
      ),
      // Ensure that the "Core" package fieldset comes first.
      '#weight' => $package == 'Core' ? -10 : NULL,
    );
  }

  // Lastly, sort all fieldsets by title.
  uasort($form['modules'], 'element_sort_by_title');

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  $form['#submit'][] = 'module_permissions_managed_modules_submit';

  return $form;
}

/**
 * Form submission handler for module_permissions_managed_modules().
 */
function module_permissions_managed_modules_submit($form, &$form_state) {
  $managed_modules = array();

  if (!empty($form_state['values']['modules'])) {
    foreach ($form_state['values']['modules'] as $modules) {
      foreach ($modules as $name => $values) {
        $modules = $values['granted'];
        if ($modules) {
          $managed_modules[] = $name;
        }
      }
    }
  }

  variable_set('module_permissions_managed_modules', $managed_modules);
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Array sorting callback; sorts modules by their name.
 */
function module_permissions_sort_modules_by_info_name($a, $b) {
  return strcasecmp($a->info['name'], $b->info['name']);
}
