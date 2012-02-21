Drupal.behaviors.initModalFormsLogin = function (context) {
  $("a[href*='/user/login'], a[href*='?q=user/login']", context).each(function () {
    this.href = this.href.replace(/user\/login/, 'modal_forms/nojs/login');
  }).addClass('init-modal-forms-login ctools-use-modal ctools-modal-modal-popup-medium');
}