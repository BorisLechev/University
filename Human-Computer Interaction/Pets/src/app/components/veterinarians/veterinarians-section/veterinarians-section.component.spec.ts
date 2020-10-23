import { ComponentFixture, TestBed } from '@angular/core/testing';

import { VeterinariansSectionComponent } from './veterinarians-section.component';

describe('VeterinariansSectionComponent', () => {
  let component: VeterinariansSectionComponent;
  let fixture: ComponentFixture<VeterinariansSectionComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ VeterinariansSectionComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(VeterinariansSectionComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
