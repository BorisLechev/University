import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './components/home/home.component';
import { NavigationComponent } from './components/shared/navigation/navigation.component';
import { ScrollDirective } from './components/shared/navigation/scroll-directive/scroll.directive';
import { TeamComponent } from './components/shared/team/team.component';
import { ArticlesSectionComponent } from './components/articles/articles-section/articles-section.component';
import { ArticleComponent } from './components/articles/article/article.component';
import { BackToTheTopArrowComponent } from './components/shared/back-to-the-top-arrow/back-to-the-top-arrow.component';
import { BackToTopDirective } from './components/shared/back-to-the-top-arrow/back-to-top-directive/back-to-top.directive';
import { ErrorPageComponent } from './components/error-page/error-page.component';
import { VeterinariansSectionComponent } from './components/veterinarians/veterinarians-section/veterinarians-section.component';
import { VeterinarianCardComponent } from './components/veterinarians/veterinarian-card/veterinarian-card.component';
import { PetShopsSectionComponent } from './components/pet-shops/pet-shops-section/pet-shops-section.component';
import { PetShopCardComponent } from './components/pet-shops/pet-shop-card/pet-shop-card.component';
import { PetDetailsComponent } from './components/pets/pet-details/pet-details.component';
import { PetsSectionComponent } from './components/pets/pets-section/pets-section.component';
import { PetCardComponent } from './components/pets/pet-card/pet-card.component';
import { ListOfPetSpeciesComponent } from './components/pets/list-of-pet-species/list-of-pet-species.component';
import { FooterComponent } from './components/shared/footer/footer.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    NavigationComponent,
    FooterComponent,
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
    ErrorPageComponent,
    VeterinariansSectionComponent,
    VeterinarianCardComponent,
    PetShopsSectionComponent,
    PetShopCardComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
