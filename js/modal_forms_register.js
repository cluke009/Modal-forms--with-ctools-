Drupal.behaviors.initModalFormsRegister = function (context) {
  $("a[href*='/user/register'], a[href*='?q=user/register']", context).each(function () {
    this.href = this.href.replace(/user\/register/, 'modal_forms/nojs/register');
  }).addClass('init-modal-forms-register ctools-use-modal ctools-modal-modal-popup-medium');
}