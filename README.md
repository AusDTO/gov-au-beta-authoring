# Experimental GOV.AU Authoring Tool

This is a technology **experiment** designed to explore the way GovCMS can be used as an authoring tool for content to be published on GOV.AU.

This is GovCMS/Drupal with an added module [govau_push](https://github.com/AusDTO/gov-au-beta-authoring/tree/master/sites/all/modules/custom/govau_push).

[govau_push](https://github.com/AusDTO/gov-au-beta-authoring/tree/master/sites/all/modules/custom/govau_push) sends content and taxonomies to an API when they are changed. It also allows logging in to the experimental application and previewing content before it is published.

This experiment is intentionally simplistic and minimises dependencies. For example it does not use the [Content Hub](https://www.acquia.com/gb/products-services/acquia-content-hub).

# Development Setup
Quickest setup is to use [Acquia Dev Desktop](https://www.acquia.com/downloads) and use the "Start with an existing site on my local computer" option.

Then after installation, go to http://gov-au-beta-authoring.dd:8083/admin/modules and enable GOV.AU Publisher/Page.

To enable xdebug, uncomment the xdebug zend_extension line in /Applications/DevDesktop/php5_5/bin/php.ini and add configuration:

    zend_extension="/Applications/DevDesktop/php5_5/ext/xdebug.so" 
    xdebug.remote_host = 127.0.0.1
    xdebug.remote_enable = 1
    xdebug.remote_port = 9000
    xdebug.remote_handler = dbgp
    xdebug.remote_mode = req
    
# TODO
Manage versioning of module and send version in any responses

# Copyright & Licensing

The govau_push module is copyright Digital Transformation Office and licensed under GNU General Public License version 2. See COPYRIGHT.txt for copyright and licensing of the main Drupal code.
