Drupal.behaviors.initModalFormsContact = function (context) {
  $("a[href*='/contact'], a[href*='?q=contact']", context).each(function () {
    this.href = this.href.replace(/contact/, 'modal_forms/nojs/contact');
  }).addClass('init-modal-forms-contact ctools-use-modal ctools-modal-modal-popup-medium');
}