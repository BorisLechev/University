import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ListOfPetSpeciesComponent } from './list-of-pet-species.component';

describe('ListOfPetSpeciesComponent', () => {
  let component: ListOfPetSpeciesComponent;
  let fixture: ComponentFixture<ListOfPetSpeciesComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ListOfPetSpeciesComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(ListOfPetSpeciesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
