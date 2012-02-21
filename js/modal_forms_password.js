Drupal.behaviors.initModalFormsPassword = function (context) {
  $("a[href*='/user/password'], a[href*='?q=user/password']", context).each(function () {
    this.href = this.href.replace(/user\/password/, 'modal_forms/nojs/password');
  }).addClass('init-modal-forms-password ctools-use-modal ctools-modal-modal-popup-medium');
}