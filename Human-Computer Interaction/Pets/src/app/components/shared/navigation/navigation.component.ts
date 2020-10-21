import { Component } from '@angular/core';

@Component({
  selector: 'app-navigation',
  templateUrl: './navigation.component.html',
  styleUrls: ['./navigation.component.scss']
})
export class NavigationComponent {

  constructor() { }

  openSidebar() {
    document.getElementById('menu-drop').style.transform = 'translateX(0%)';
  }

  closeSidebar() {
    document.getElementById('menu-drop').style.transform = 'translateX(-100%)';
  }
}