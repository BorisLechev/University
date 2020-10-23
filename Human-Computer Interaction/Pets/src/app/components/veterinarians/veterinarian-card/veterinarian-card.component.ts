import { Input } from '@angular/core';
import { Component, OnInit } from '@angular/core';
import { VeterinarianModel } from '../../shared/models/VeterinarianModel';

@Component({
  selector: 'app-veterinarian-card',
  templateUrl: './veterinarian-card.component.html',
  styleUrls: ['./veterinarian-card.component.scss']
})
export class VeterinarianCardComponent implements OnInit {
  @Input('veterinarian')
  veterinarian: VeterinarianModel;

  constructor() { }

  ngOnInit(): void {
  }
}
