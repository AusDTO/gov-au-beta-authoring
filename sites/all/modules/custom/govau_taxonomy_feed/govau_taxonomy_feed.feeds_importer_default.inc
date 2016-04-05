<?php
/**
 * @file
 * govau_taxonomy_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function govau_taxonomy_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'taxonomy_feed';
  $feeds_importer->config = array(
    'name' => 'GOV.AU Taxonomy Feed',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJmesPathLines',
      'config' => array(
        'sources' => array(
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'debug' => 1,
            'weight' => '1',
          ),
          'url' => array(
            'name' => 'url',
            'value' => 'url',
            'debug' => 1,
            'weight' => '2',
          ),
        ),
        'display_errors' => 0,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'context' => array(
          'value' => '',
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'url',
            'target' => 'meta_canonical',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'tags',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['taxonomy_feed'] = $feeds_importer;

  return $export;
}
