<?php
/**
 * @file
 * smtp_settings.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function smtp_settings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
