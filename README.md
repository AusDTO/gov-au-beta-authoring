# Experimental GOV.AU Authoring Tool

This is a technology **experiment** designed to explore the way GovCMS can be used as an authoring tool for content to be published on GOV.AU.

This is GovCMS/Drupal with an added module [govau_push](https://github.com/AusDTO/gov-au-beta-authoring/tree/master/sites/all/modules/custom/govau_push).

[govau_push](https://github.com/AusDTO/gov-au-beta-authoring/tree/master/sites/all/modules/custom/govau_push) sends content and taxonomies to an API when they are changed. It also allows logging in to the experimental application and previewing content before it is published.

This experiment is intentionally simplistic and minimises dependencies. For example it does not use the [Content Hub](https://www.acquia.com/gb/products-services/acquia-content-hub).

## GOV.AU stack
If you're contributing to this repo, then you'll most likely be contributing to the other GOV.AU repos in the stack:

* [GOV.AU Beta Frontend](https://github.com/AusDTO/gov-au-beta)
* [GOV.AU Content Analysis](https://github.com/AusDTO/gov-au-beta-content-analysis)

# Development Setup
Quickest setup is to use [Acquia Dev Desktop](https://www.acquia.com/downloads) and use the "Start with an existing site on my local computer" option, then go to http://gov-au-beta-authoring.dd:8083/install.php to do the initial setup.
 
Then after installation, go to http://gov-au-beta-authoring.dd:8083/admin/modules and enable GOV.AU Publisher/Page.

To enable xdebug, uncomment the xdebug zend_extension line in /Applications/DevDesktop/php5_5/bin/php.ini and add configuration:

    zend_extension="/Applications/DevDesktop/php5_5/ext/xdebug.so" 
    xdebug.remote_host = 127.0.0.1
    xdebug.remote_enable = 1
    xdebug.remote_port = 9000
    xdebug.remote_handler = dbgp
    xdebug.remote_mode = req

# Configuration

You will need to configure several parts of Drupal in order to work with GOV.AU. 

These settings can be found under `Home > Administration > Configuration > Content Authoring > GOV.AU Push module settings`

## GOVAU API URLS

You will need to set the following:

**GOV.AU API URL**

This is required for Drupal to notify GOVAU of content changes. This should be set to the URL of the core GOV.AU service.

**GOV.AU Content Analysis API URL**

This is required for Drupal's GOV.AU Content Linting block (or any other content analysis feature). This should be set to the URL of the GOV.AU content analysis service.

## GOV.AU Content Quality Block

This is required to display the content analysis block onto a node's view.

This can be found under `Home > Administration > Structure > Blocks`

## GOVAU Content Linting

Move the block from the available list of blocks to under 'Main page content' under the Content section.


    
# TODO
Manage versioning of module and send version in any responses

# Copyright & Licensing

The govau_push module is copyright Digital Transformation Office and licensed under GNU General Public License version 2. See COPYRIGHT.txt for copyright and licensing of the main Drupal code.
