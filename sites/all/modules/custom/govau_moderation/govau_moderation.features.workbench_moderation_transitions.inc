<?php
/**
 * @file
 * govau_moderation.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function govau_moderation_workbench_moderation_export_transitions() {
  $items = array(
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:publish_pending' => array(
      'from_name' => 'needs_review',
      'to_name' => 'publish_pending',
      'name' => 'Publish',
    ),
    'publish_pending:draft' => array(
      'from_name' => 'publish_pending',
      'to_name' => 'draft',
      'name' => 'Publish Failure',
    ),
    'publish_pending:published' => array(
      'from_name' => 'publish_pending',
      'to_name' => 'published',
      'name' => 'Publish Successful',
    ),
  );
  return $items;
}
