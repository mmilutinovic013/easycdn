<?php

/**
 * @file
 * Settings administration UI.
 */


//----------------------------------------------------------------------------
// Form API callbacks.

/**
 * Form definition; general settings.
 */
function easycdn_admin_general_settings_form($form, &$form_state) {
  $form = array();
  $rows = array();
  $header = array();

  $libraries = libraries_detect();
  dpm($libraries);
  foreach ($libraries as $machine_name => $library) {
    array_push($header, $libraries[$machine_name]['machine name']);
    // This is to specify the vertical tab holder.
    // One page can have two vertical tabs, but it's always one main tab with sub tabs.
    $form['easycdn']['explanation'] = array(
      '#title' => t('Choose from the libraries below and adjust its settings to choose to serve its files from a cdn or locally.'),
      );
    $form['easycdn'][$machine_name] = array(
      '#type' => 'fieldset',
      '#title' => t($machine_name),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      );
      
    $form['easycdn'][$machine_name]['easycdn_cdn-' . $machine_name] = array(
      '#title' => t('CDN Choice'),
      '#type' => 'select',
      '#options' => array(
        0 => t('Local'),
        1 => t('jsDelivr (Supported in China)'),
        2 => t('CDNJS (Limited China Support)'),
        ),
      '#default_value' => variable_get('easycdn_cdn-' . $machine_name, ''),

    );
    $form['easycdn'][$machine_name]['easycdn_version-' . $machine_name] = array(
      '#title' => t('Version'),
      '#type' => 'select',
      '#options' => array(
        $libraries[$machine_name]['version']
        ),
      '#default_value' => variable_get('easycdn_version-'. $machine_name, ''),
    );
  }

  dpm($form);

  return system_settings_form($form);
}

function easycdn_admin_general_settings_form_submit($form, &$form_state) {
  // Clean the form_state
  dpm($form);
  dpm($form_state);
  form_state_values_clean($form_state);
  foreach ($libraries as $machine_name => $value) {
    # code...
  }
  $var['tag'] = $form_state['values']['tag'];
  // Update the versions & files
  // Rebuild the form
  $form_state['rebuild'] = TRUE;
}
