import { Component, OnInit } from '@angular/core';
import { PetShopModel } from '../../shared/models/PetShopModel';

@Component({
  selector: 'app-pet-shops-section',
  templateUrl: './pet-shops-section.component.html',
  styleUrls: ['./pet-shops-section.component.scss']
})
export class PetShopsSectionComponent implements OnInit {
  petShops: PetShopModel[] = [
    { name: "д-р стефанов", address: "бул. Сливница 185, Delta Planet", phone: "0895 55 28 04", workingTime: "10:00-21:00ч.", town: "варна" },
    { name: "Maxi pet", address: "бул. Вл. Варненчик", phone: "024373630", workingTime: "09:00-21:00ч.", town: "варна" },
    { name: "Zooland Varna", address: "ул. Девня 17 ЖП гара варна", phone: "087 796 5422", workingTime: "09:00-19:00ч.", town: "варна" },
    { name: "д-р стефанов", address: "кв. Студентски град, ъл. Акад. Стефан Младенов 76", phone: "0887797330", workingTime: "10:00-21:00ч.", town: "софия" },
    { name: "д-р стефанов", address: "кв. Люлин бл. 386", phone: "0895606946", workingTime: "10:00-20:00ч.", town: "софия" },
    { name: "д-р стефанов", address: "к.в. Овча  купел, ул. Любляна 37", phone: "0895552806", workingTime: "10:00-20:00ч.", town: "софия" },
    { name: "Еврозоовет Скалар", address: "ул. Авксентий Велешки", phone: "032 630 207", workingTime: "09:30-19:30ч.", town: "пловдив" },
    { name: "Zoomania megastore", address: "ул. Менделеев 2б", phone: "0885230809", workingTime: "10:00-19:00ч.", town: "пловдив" },
    { name: "Заравет", address: "ж.к. Тракия, ул. Княз Борис I 9", phone: "032682791", workingTime: "08:00-21:00ч.", town: "пловдив" },
  ];

  constructor() { }

  ngOnInit(): void {
  }

}
