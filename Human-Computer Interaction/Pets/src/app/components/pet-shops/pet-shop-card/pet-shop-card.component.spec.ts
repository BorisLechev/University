import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PetShopCardComponent } from './pet-shop-card.component';

describe('PetShopCardComponent', () => {
  let component: PetShopCardComponent;
  let fixture: ComponentFixture<PetShopCardComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PetShopCardComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(PetShopCardComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
