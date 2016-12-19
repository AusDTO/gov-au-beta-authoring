<?php
/**
 * @file
 * govau_moderation.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function govau_moderation_user_default_roles() {
  $roles = array();

  // Exported role: Content approver.
  $roles['Content approver'] = array(
    'name' => 'Content approver',
    'weight' => 2,
  );

  // Exported role: Content editor.
  $roles['Content editor'] = array(
    'name' => 'Content editor',
    'weight' => 1,
  );

  return $roles;
}
