import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { ArticleComponent } from './components/articles/article/article.component';
import { ArticlesSectionComponent } from './components/articles/articles-section/articles-section.component';
import { ErrorPageComponent } from './components/error-page/error-page.component';
import { HomeComponent } from './components/home/home.component';
import { ListOfPetSpeciesComponent } from './components/list-of-pet-species/list-of-pet-species.component';
import { PetShopsSectionComponent } from './components/pet-shops/pet-shops-section/pet-shops-section.component';
import { PetDetailsComponent } from './components/pets/pet-details/pet-details.component';
import { PetsSectionComponent } from './components/pets/pets-section/pets-section.component';
import { VeterinarianCardComponent } from './components/veterinarians/veterinarian-card/veterinarian-card.component';
import { VeterinariansSectionComponent } from './components/veterinarians/veterinarians-section/veterinarians-section.component';

const routes: Routes = [
  { path: '', redirectTo: 'home', pathMatch: 'full' },
  { path: '', component: HomeComponent },
  { path: 'articles', component: ArticlesSectionComponent },
  { path: 'species', component: ListOfPetSpeciesComponent },
  { path: 'pets/:type', component: PetsSectionComponent},
  { path: 'pet/:id', component: PetDetailsComponent },
  { path: "veterinarians", component: VeterinariansSectionComponent },
  { path: "petshops", component: PetShopsSectionComponent },
  { path: 'error', component: ErrorPageComponent },
  { path: '**', redirectTo: 'error' },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
