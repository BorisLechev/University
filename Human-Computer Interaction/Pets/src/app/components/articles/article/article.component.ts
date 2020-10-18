import { Component, Input, OnInit } from '@angular/core';
import { ArticleModel } from '../../shared/models/ArticleModel';

@Component({
  selector: 'app-article',
  templateUrl: './article.component.html',
  styleUrls: ['./article.component.scss']
})
export class ArticleComponent implements OnInit {
  @Input('article')
  article: ArticleModel;

  constructor() { }

  ngOnInit(): void {
  }

}
