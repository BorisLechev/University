import { Directive, ElementRef, HostListener, Renderer2 } from '@angular/core';

@Directive({
  selector: '[appScroll]'
})
export class ScrollDirective {

  constructor(
    private element: ElementRef,
    private renderer: Renderer2
  ) { }

  @HostListener('window:scroll')
  onWindowScroll() {
    if (window.pageYOffset) {
      this.renderer.addClass(this.element.nativeElement, 'white');
    } else {
      this.renderer.removeClass(this.element.nativeElement, 'white');
    }
  }
}
