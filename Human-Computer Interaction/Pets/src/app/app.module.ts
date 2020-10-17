import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './components/home/home.component';
import { NavigationComponent } from './components/shared/navigation/navigation.component';
import { ScrollDirective } from './components/shared/navigation/scroll-directive/scroll.directive';
import { TeamComponent } from './components/shared/team/team.component';
import { ListOfPetSpeciesComponent } from './components/list-of-pet-species/list-of-pet-species.component';
import { BackToTopDirective } from './components/home/back-to-top-directive/back-to-top.directive';
import { PetDetailsComponent } from './components/pets/pet-details/pet-details.component';
import { PetsSectionComponent } from './components/pets/pets-section/pets-section.component';
import { PetCardComponent } from './components/pets/pet-card/pet-card.component';

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
    PetCardComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
