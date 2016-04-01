<?php
/**
 * @file
 * Callbacks for building blocks.
 */

/**
 * Page callback for google-analytics-reports/ajax/path-mini.
 */
function google_analytics_reports_path_mini_ajax() {
  $path = isset($_GET['path']) ? $_GET['path'] : '/index.html';
  drupal_json_output(google_analytics_reports_path_mini_build($path));
}

/**
 * Page callback for google-analytics-reports/ajax/dashboard.
 */
function google_analytics_reports_dashboard_ajax() {
  drupal_json_output(google_analytics_reports_dashboard_build());
}

/**
 * Generates a block with the current page statistics.
 */
function google_analytics_reports_path_mini_build($path) {
  if (!variable_get('google_analytics_reports_oauth_token', FALSE)) {
    return '<p>' . t('You must <a href="!url">authorize</a> Drupal to use your Analytics account before you can view reports.', array('!url' => url('admin/config/system/google-analytics-reports'))) . '</p>';
  }

  if ($path == '/') {
    $path = '/index.html';
  }

  $params = array(
    'metrics' => array('ga:pageviews'),
    'dimensions' => array('ga:date'),
    'sort_metric' => array('ga:date'),
    'filters' => _google_analytics_reports_path_filter($path),
    'start_date' => strtotime('-31 days'),
    'end_date' => strtotime('-1 day'),
  );
  $feed = google_analytics_api_report_data($params);
  if ($feed->error) {
    return '<p>' . _google_analytics_reports_error_message() . '</p>';
  }
  $max_visits = 0;
  $data = array();
  foreach ($feed->results as $row) {
    $data[] = $row['pageviews'];
    $max_visits = max($row['pageviews'], $max_visits);
  }

  $series = array('No of pageviews' => $data);
  $settings = array();
  $settings['chart']['pageviews_small_30d'] = array(
    'containerId' => 'pageviews_small_30d',
    'header' => array_fill(0, count($data), ''),
    'rows' => array_values($series),
    'columns' => array_keys($series),
    'chartType' => 'AreaChart',
    'options' => array(
      'title' => 'Pageviews',
      'width' => '100%',
      'height' => 40,
      'axisTitlesPosition' => 'none',
      'vAxis' => array(
        'textPosition' => 'none',
        'baselineColor' => 'transparent',
        'gridlines' => array(
          'color' => 'transparent',
        ),
      ),
      'legend' => array(
        'position' => 'none',
      ),
      'chartArea' => array(
        'width' => '100%',
        'height' => '100%',
      ),
      'colors' => array('#AAAAAA'),
    ),
  );
  $chart = draw_chart($settings);
  $report['chart'] = l($chart['markup'], 'admin/reports/google-analytics/detail', array('query' => array('path' => $path), 'html' => TRUE));

  $report['views'] = l(t('@views views this month', array('@views' => number_format($feed->totals['pageviews']))), 'admin/reports/google-analytics/detail', array('query' => array('path' => $path)));
  return array(
    'content' => theme('google_analytics_reports_path_mini', $report),
    'settings' => $settings,
  );
}

/**
 * Generates the dashboard block.
 */
function google_analytics_reports_dashboard_build() {
  $params = array(
    'metrics' => array('ga:visits'),
    'dimensions' => array('ga:date'),
    'sort_metric' => array('ga:date'),
    'start_date' => strtotime('-31 days'),
    'end_date' => strtotime('-1 day'),
  );
  $feed = google_analytics_api_report_data($params);
  if ($feed->error) {
    return FALSE;
  }
  $max_visits = 0;
  $data = array();
  foreach ($feed->results as $row) {
    $data[] = $row['visits'];
    $max_visits = max($row['visits'], $max_visits);
  }

  $series = array('No of visits' => $data);
  $settings = array();
  $settings['chart']['visits_large_30d'] = array(
    'containerId' => 'visits_large_30d',
    'header' => array_fill(0, count($data), ''),
    'rows' => array_values($series),
    'columns' => array_keys($series),
    'chartType' => 'AreaChart',
    'options' => array(
      'title' => 'Pageviews',
      'width' => '100%',
      'height' => 80,
      'axisTitlesPosition' => 'none',
      'vAxis' => array(
        'textPosition' => 'none',
        'baselineColor' => 'transparent',
        'gridlines' => array(
          'color' => 'transparent',
        ),
      ),
      'legend' => array(
        'position' => 'none',
      ),
      'chartArea' => array(
        'width' => '100%',
        'height' => '100%',
      ),
      'colors' => array('#AAAAAA'),
    ),
  );
  $chart = draw_chart($settings);
  $report['chart'] = l($chart['markup'], 'admin/reports/google-analytics', array('html' => TRUE));

  $report['visits'] = l(t('@visits visits this month', array('@visits' => number_format($feed->totals['visits']))), 'admin/reports/google-analytics');
  return array(
    'content' => theme('google_analytics_reports_dashboard', $report),
    'settings' => $settings,
  );
}
