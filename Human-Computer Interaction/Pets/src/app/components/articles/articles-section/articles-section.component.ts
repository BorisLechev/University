import { Component, OnInit } from '@angular/core';
import { ArticleModel } from '../../shared/models/ArticleModel';

@Component({
  selector: 'app-articles-section',
  templateUrl: './articles-section.component.html',
  styleUrls: ['./articles-section.component.scss']
})
export class ArticlesSectionComponent implements OnInit {
  articles: ArticleModel[] = [
    { id: 1, title: "С наднормено тегло ли е кучето ви?", content: "При кучетата както и при хората някой и друг килограм се качва лесно, особено когато кучето старее и е по-малко активно", likes: 2, comments: 12, publishedOn: "16 oct 2020" },
    { id: 2, title: "Най-полезните 10 неща, които можем да научим от кучетата", content: "Кучето е единственото същество на земята, което ви обича повече, отколкото обича себе си. Кучетата развиват доживотна връзка с хората, които се грижат за тях.Човек може да научи много от кучетата за това как да живее всеки ден с изключителен ентусиазъм и радост, за това как да сграбчва мига и да следва сърцето си въпреки всичко. Те ни учат на приятелство и безкористност и най-вече на непоклатима в", likes: 2, comments: 12, publishedOn: "18 oct 2020" },
  ];
  constructor() { }

  ngOnInit(): void {
  }

}
