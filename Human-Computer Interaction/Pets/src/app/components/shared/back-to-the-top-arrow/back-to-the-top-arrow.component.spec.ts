import { ComponentFixture, TestBed } from '@angular/core/testing';

import { BackToTheTopArrowComponent } from './back-to-the-top-arrow.component';

describe('BackToTheTopArrowComponent', () => {
  let component: BackToTheTopArrowComponent;
  let fixture: ComponentFixture<BackToTheTopArrowComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ BackToTheTopArrowComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(BackToTheTopArrowComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
