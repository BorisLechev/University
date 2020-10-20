import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './components/home/home.component';
import { NavigationComponent } from './components/shared/navigation/navigation.component';
import { ScrollDirective } from './components/shared/navigation/scroll-directive/scroll.directive';
import { TeamComponent } from './components/shared/team/team.component';
import { ListOfPetSpeciesComponent } from './components/list-of-pet-species/list-of-pet-species.component';
import { PetDetailsComponent } from './components/pets/pet-details/pet-details.component';
import { PetsSectionComponent } from './components/pets/pets-section/pets-section.component';
import { PetCardComponent } from './components/pets/pet-card/pet-card.component';
import { ArticlesSectionComponent } from './components/articles/articles-section/articles-section.component';
import { ArticleComponent } from './components/articles/article/article.component';
import { BackToTheTopArrowComponent } from './components/shared/back-to-the-top-arrow/back-to-the-top-arrow.component';
import { BackToTopDirective } from './components/shared/back-to-the-top-arrow/back-to-top-directive/back-to-top.directive';
import { ErrorPageComponent } from './components/error-page/error-page.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    NavigationComponent,
    ScrollDirective,
    TeamComponent,
    ListOfPetSpeciesComponent,
    BackToTopDirective,
    PetDetailsComponent,
    PetsSectionComponent,
    PetCardComponent,
    ArticlesSectionComponent,
    ArticleComponent,
    BackToTheTopArrowComponent,
    ErrorPageComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
