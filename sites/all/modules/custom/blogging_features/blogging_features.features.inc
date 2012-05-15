<?php
/**
 * @file
 * blogging_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function blogging_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function blogging_features_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function blogging_features_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Blog articles'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
