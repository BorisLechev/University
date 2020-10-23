import { ComponentFixture, TestBed } from '@angular/core/testing';

import { VeterinarianCardComponent } from './veterinarian-card.component';

describe('VeterinarianCardComponent', () => {
  let component: VeterinarianCardComponent;
  let fixture: ComponentFixture<VeterinarianCardComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ VeterinarianCardComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(VeterinarianCardComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
