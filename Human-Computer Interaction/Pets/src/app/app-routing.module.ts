import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { ArticleComponent } from './components/articles/article/article.component';
import { ArticlesSectionComponent } from './components/articles/articles-section/articles-section.component';
import { ErrorPageComponent } from './components/error-page/error-page.component';
import { HomeComponent } from './components/home/home.component';
import { ListOfPetSpeciesComponent } from './components/list-of-pet-species/list-of-pet-species.component';
import { PetDetailsComponent } from './components/pets/pet-details/pet-details.component';
import { PetsSectionComponent } from './components/pets/pets-section/pets-section.component';

const routes: Routes = [
  { path: '', redirectTo: 'home', pathMatch: 'full' },
  { path: '', component: HomeComponent },
  { path: 'articles', component: ArticlesSectionComponent },
  { path: 'species', component: ListOfPetSpeciesComponent },
  { path: 'pets/:type', component: PetsSectionComponent},
  { path: 'pet/:id', component: PetDetailsComponent },
  { path: 'error', component: ErrorPageComponent },
  { path: '**', redirectTo: 'error' },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
