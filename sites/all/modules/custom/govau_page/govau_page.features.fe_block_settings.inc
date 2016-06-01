<?php
/**
 * @file
 * govau_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function govau_page_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['govau_publisher-govau_publisher'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'govau_publisher',
    'module' => 'govau_publisher',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'govcms_barton' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'govcms_barton',
        'weight' => -24,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
