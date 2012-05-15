<?php
/**
 * @file
 * blogging_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function blogging_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = 'When viewing a blog post';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'comment-recent' => array(
          'module' => 'comment',
          'delta' => 'recent',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-blog_archive-block' => array(
          'module' => 'views',
          'delta' => 'blog_archive-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('When viewing a blog post');
  $export['blog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_archive';
  $context->description = 'The blog view/blog archive view';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blog:page' => 'blog:page',
        'blog_archive:page' => 'blog_archive:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-blog_archive-block' => array(
          'module' => 'views',
          'delta' => 'blog_archive-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The blog view/blog archive view');
  $export['blog_archive'] = $context;

  return $export;
}
