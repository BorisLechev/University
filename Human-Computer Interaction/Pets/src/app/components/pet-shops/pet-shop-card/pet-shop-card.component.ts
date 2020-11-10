import { Input } from '@angular/core';
import { Component, OnInit } from '@angular/core';
import { PetShopModel } from '../../shared/models/PetShopModel';

@Component({
  selector: 'app-pet-shop-card',
  templateUrl: './pet-shop-card.component.html',
  styleUrls: ['./pet-shop-card.component.scss']
})
export class PetShopCardComponent implements OnInit {
  @Input('petShop')
  petShop: PetShopModel;
  // petUrl: string = "https://zoomagazin.bg/";
  constructor() { }

  ngOnInit(): void {
  }

}
