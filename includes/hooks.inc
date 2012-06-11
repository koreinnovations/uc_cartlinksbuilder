<?php

/*
 * Implementation of hook_perm().
 */
function uc_cartlinksbuilder_perm() {
  return array(
      'access cart links builder tool',
  );
}

/**
 * Implementation of hook_menu().
 */
function uc_cartlinksbuilder_menu() {
  $items['admin/store/cart-links-builder'] = array(
      'title' => 'Cart Links Builder',
      'page callback' => 'drupal_get_form',
      'page arguments' => array('uc_cartlinksbuilder_builder_form'),
      'access arguments' => array('access cart links builder tool'),
      'file' => 'includes/forms.inc',
  );
  $items['uc-cartlinksbuilder/autocomplete'] = array(
      'type' => MENU_CALLBACK,
      'page callback' => 'uc_cartlinksbuilder_product_autocomplete',
      'access arguments' => array('access cart links builder tool'),
      'file' => 'includes/ajax.inc',
  );

  return $items;
}