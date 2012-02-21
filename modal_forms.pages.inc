<?php
/**
 * @file
 * Page callbacks for the modal_forms module.
 */

/*
 * A modal user login callback.
 */
function modal_forms_login($js = NULL) {
  // Fall back if $js is not set.
  if (!$js) {
    return drupal_get_form('user_login');
  }

  ctools_include('modal');
  ctools_include('ajax');
  $form_state = array(
    'title' => t('Log in'),
    'ajax' => TRUE,
  );

  $output = ctools_modal_form_wrapper('user_login', $form_state);
  if (!empty($form_state['executed'])) {
    // We'll just overwrite the form output if it was successful.
    $output = array();
    ctools_add_js('ajax-responder');
    $output[] = ctools_modal_command_dismiss(t('Login success'));
    if (isset($_GET['destination'])) {
      $output[] = ctools_ajax_command_redirect($_GET['destination']);
    }
    else {
      $output[] = ctools_ajax_command_reload();
    }
  }
  ctools_ajax_render($output);
}

/**
 * A modal user register callback.
 */
function modal_forms_register($js = NULL) {
  // Fall back if $js is not set.
  if (!$js) {
    return drupal_get_form('user_register');
  }

  ctools_include('modal');
  ctools_include('ajax');
  $form_state = array(
    'title' => t('Create new account'),
    'ajax' => TRUE,
  );
  $output = ctools_modal_form_wrapper('user_register', $form_state);
  if (!empty($form_state['executed'])) {
    // We'll just overwrite the form output if it was successful.
    $output = array();
    ctools_add_js('ajax-responder');
    if (isset($_GET['destination'])) {
      $output[] = ctools_ajax_command_redirect($_GET['destination']);
    }
    else {
      $output[] = ctools_ajax_command_reload();
    }
  }
  ctools_ajax_render($output);
}

/**
 * A modal user password callback.
 */
function modal_forms_password($js = NULL) {
  module_load_include('inc', 'user', 'user.pages');

  // Fall back if $js is not set.
  if (!$js) {
    return drupal_get_form('user_pass');
  }

  ctools_include('modal');
  ctools_include('ajax');
  $form_state = array(
    'title' => t('Request new password'),
    'ajax' => TRUE,
  );
  $output = ctools_modal_form_wrapper('user_pass', $form_state);
  if (!empty($form_state['executed'])) {
    // We'll just overwrite the form output if it was successful.
    $output = array();
    ctools_add_js('ajax-responder');
    if (isset($_GET['destination'])) {
      $output[] = ctools_ajax_command_redirect($_GET['destination']);
    }
    else {
      $output[] = ctools_ajax_command_reload();
    }
  }
  ctools_ajax_render($output);
}

/**
 * A modal contact callback.
 */
function modal_forms_contact($js = NULL) {
  module_load_include('inc', 'contact', 'contact.pages');

  // Fall back if $js is not set.
  if (!$js) {
    return drupal_get_form('contact_mail_page');
  }

  ctools_include('modal');
  ctools_include('ajax');
  $form_state = array(
    'title' => t('Contact'),
    'ajax' => TRUE,
  );
  $output = ctools_modal_form_wrapper('contact_mail_page', $form_state);
  if (!empty($form_state['executed'])) {
    // We'll just overwrite the form output if it was successful.
    $output = array();
    ctools_add_js('ajax-responder');
    if (isset($_GET['destination'])) {
      $output[] = ctools_ajax_command_redirect($_GET['destination']);
    }
    else {
      $output[] = ctools_ajax_command_reload();
    }
  }
  ctools_ajax_render($output);
}
