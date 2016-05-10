<?php
/**
 * @file
 * A temporary demonstration page. Will be removed once integration complete.
 */

/**
 * Demo page callback.
 */
function govcms_ckan_demo_page() {
  $output = array();
  $dataset = '531eb12d-4c60-4cdc-a26e-e500188c0d33';

  // Get a client and fetch response.
  $client = govcms_ckan_client();
  $response = $client->get('action/datastore_search', array('id' => $dataset));

  // Public URL.
  $public_url = variable_get('govcms_ckan_endpoint_url', '') . '/dataset/' . $dataset;

  // Page header.
  $output[] = '<p>Dataset: ' . $dataset . '</p>';
  $output[] = '<p><strong>' . l(t('> Go to dataset on data.gov.au'), $public_url) . '</strong></p>';

  // Get the Keys to use in the result set. These will be configurable via
  // admin but for now, hard coded for this dataset.
  $keys = _govcms_ckan_demo_get_keys();

  // Get a parser class.
  $parser = govcms_ckan_dataset_parser();

  // Chart class.
  $chart_class = 'table-chart-demo';

  // Chart types.
  $chart_types = array('area', 'bar');

  // Parsing types.
  $table_set = array('keys' => 'Keys header', 'value' => 'Value header');

  // Present the data in two different formats depending on what should form the
  // lines vs axis labels.
  foreach ($table_set as $tick_source => $title) {

    // Parse the data.
    $tables = $parser
      ->setHeaderSource($tick_source)
      ->setResult($response->data)
      ->setKeys($keys)
      ->setLabelKey('Taxa')
      ->setGroupKey('Year')
      ->setRenderableArray(FALSE)
      ->parse();

    // Add a title.
    $output[] = '<br /><h2>' . $title . '</h2><hr />';

    // Create a couple of chart types with the same data.
    foreach ($chart_types as $type) {
      // Attributes for chart usage.
      $table_defaults = array(
        'sticky' => FALSE,
        'attributes' => array(
          'class' => array($chart_class),
          'data-type' => $type,
          'data-stacked' => 'true',
          'data-grid' => 'y',
          'data-xLabel' => 'Type',
          'data-yLabel' => 'Amount',
        ),
      );

      // This is RAW AS, definately not permanent.
      foreach ($tables as $year => $table_vars) {
        $output[] = '<div class="year-set" id="year-set-' . $year . '"><br />';
        $output[] = '<h3>' . $year . ' (' . ucwords($type) . ' chart)</h3>';
        $table_vars = array_merge($table_vars, $table_defaults);
        $output[] = theme('table', $table_vars);
        $output[] = '<br /></div>';
      }
    }

  }

  // Add the JS to the tables.
  govcms_ckan_display_add_charts('.' . $chart_class);

  return implode('', $output);
}

/**
 * Get the keys for this dataset.
 */
function _govcms_ckan_demo_get_keys() {
  return array(
    'Taxa',
    'Endangered',
    'CriticallyEndangered',
    'ConservationDependent',
    'Vulnerable',
  );
}
