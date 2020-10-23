import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PetShopsSectionComponent } from './pet-shops-section.component';

describe('PetShopsSectionComponent', () => {
  let component: PetShopsSectionComponent;
  let fixture: ComponentFixture<PetShopsSectionComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PetShopsSectionComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(PetShopsSectionComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
