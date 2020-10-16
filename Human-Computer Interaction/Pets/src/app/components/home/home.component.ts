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
    // let linkTag = document.getElementById("scrollDownArrow");
    // linkTag.addEventListener("click", function (e) {
    //   e.preventDefault();
    //   let linkUrl = linkTag.getAttribute("href").replace("#", "");
    //   let destinationOffsetTop = document.getElementById(linkUrl).offsetTop;

    //   // if (linkUrl.length) {
    //     document.querySelectorAll("html, body")[0].animate({ scrollTop: destinationOffsetTop });
    //   // }
    // });

    $("#back-to-top-arrow").click(function (event) {
      event.preventDefault();

      $("html,body").animate({ scrollTop:0 }, 1000);
    });
  }
}
