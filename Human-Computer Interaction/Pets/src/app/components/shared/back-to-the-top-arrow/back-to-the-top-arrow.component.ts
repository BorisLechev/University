import { Component, OnInit } from '@angular/core';
import * as $ from 'jquery';

@Component({
  selector: 'app-back-to-the-top-arrow',
  templateUrl: './back-to-the-top-arrow.component.html',
  styleUrls: ['./back-to-the-top-arrow.component.scss']
})
export class BackToTheTopArrowComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
    $("#back-to-top-arrow").click(function (event) {
      event.preventDefault();

      $("html,body").animate({ scrollTop:0 }, 1000);
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
  }
}
