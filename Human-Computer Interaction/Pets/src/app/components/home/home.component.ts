import * as $ from 'jquery';
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})
export class HomeComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
    $("a[href^='#']").click(function (event){
      event.preventDefault();

      let target = $($(this).attr("href"));

      if (target.length){
        $("html,body").animate({ scrollTop:target.offset().top }, 1000);
      }
    });
  }
}
