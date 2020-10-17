import { Component, OnInit } from '@angular/core';
import { PetCardModel } from '../../shared/models/PetCardModel';

@Component({
  selector: 'app-pets-section',
  templateUrl: './pets-section.component.html',
  styleUrls: ['./pets-section.component.scss']
})
export class PetsSectionComponent implements OnInit {
  pets: PetCardModel[] = [
    { id: 1, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/australian_shepherd_400x378_2.jpg", breed: "Австралийска овчарка" },
    { id: 2, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/australianterrier_400x378_2.jpg", breed: "Австралийски териер" },
    { id: 3, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/australian_cattle_dog_400x378_2.jpg", breed: "Австралийско пастирско куче" },
    { id: 4, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/japaneseakita_400x378_2.jpg", breed: "Акита Ину" },
    { id: 5, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/americancockersp_400x378_0.jpg", breed: "Американски кокер шпаньол" },
  ];
  constructor() { }

  ngOnInit(): void {
  }

}
