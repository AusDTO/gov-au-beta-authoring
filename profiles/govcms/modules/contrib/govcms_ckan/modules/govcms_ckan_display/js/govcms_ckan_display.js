/**
 * govCMS CKAN Display.
 */
(function ($){

  /**
   * Display charts based on selector passed from settings.
   */
  Drupal.behaviors.tableCharts = {
    attach: function (context, settings) {

      // Only auto add if we have settings.
      if (settings.govcmsCkanDisplay === undefined) {
        return;
      }

      // Tables to act on.
      var $tables = $(settings.govcmsCkanDisplay.tableChartSelectors.join(','), context);

      // Add tableCharts.
      $tables.once('table-charts').tableCharts();

    }
  };

})(jQuery);
