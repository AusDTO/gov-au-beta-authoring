<?php
/**
 * @file
 * govau_moderation.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function govau_moderation_workbench_moderation_export_states() {
  $items = array(
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => -10,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Ready for moderation',
      'weight' => -9,
    ),
    'publish_pending' => array(
      'name' => 'publish_pending',
      'label' => 'Publish Pending',
      'description' => 'Make this version live',
      'weight' => -8,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Live version',
      'weight' => -7,
    ),
  );
  return $items;
}
