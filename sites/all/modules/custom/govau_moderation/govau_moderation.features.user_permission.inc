<?php
/**
 * @file
 * govau_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function govau_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to publish_pending'.
  $permissions['moderate content from needs_review to publish_pending'] = array(
    'name' => 'moderate content from needs_review to publish_pending',
    'roles' => array(
      'Content approver' => 'Content approver',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from publish_pending to draft'.
  $permissions['moderate content from publish_pending to draft'] = array(
    'name' => 'moderate content from publish_pending to draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from publish_pending to published'.
  $permissions['moderate content from publish_pending to published'] = array(
    'name' => 'moderate content from publish_pending to published',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
