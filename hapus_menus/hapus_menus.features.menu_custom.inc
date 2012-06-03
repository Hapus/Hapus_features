<?php
/**
 * @file
 * hapus_menus.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function hapus_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-documentation-menu
  $menus['menu-documentation-menu'] = array(
    'menu_name' => 'menu-documentation-menu',
    'title' => 'Documentation menu',
    'description' => 'All documentation and API.',
  );
  // Exported menu: menu-pricing-menu
  $menus['menu-pricing-menu'] = array(
    'menu_name' => 'menu-pricing-menu',
    'title' => 'Pricing menu',
    'description' => 'Pricing menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All documentation and API.');
  t('Documentation menu');
  t('Main menu');
  t('Pricing menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
