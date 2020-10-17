import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { PetCardModel } from '../../shared/models/PetCardModel';

@Component({
  selector: 'app-pets-section',
  templateUrl: './pets-section.component.html',
  styleUrls: ['./pets-section.component.scss']
})
export class PetsSectionComponent implements OnInit {
  public petType: string;
  dogsCollection: PetCardModel[];
  catsCollection: PetCardModel[];
  pets: PetCardModel[] = [
    { id: 1, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/australian_shepherd_400x378_2.jpg", type: "dogs", breed: "Австралийска овчарка" },
    { id: 2, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/australianterrier_400x378_2.jpg", type: "dogs", breed: "Австралийски териер" },
    { id: 3, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/australian_cattle_dog_400x378_2.jpg", type: "dogs", breed: "Австралийско пастирско куче" },
    { id: 4, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/japaneseakita_400x378_2.jpg", type: "dogs", breed: "Акита Ину" },
    { id: 5, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/americancockersp_400x378_0.jpg", type: "dogs", breed: "Американски кокер шпаньол" },
    { id: 6, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/cat_abyssiniansorrel_400x378_0.jpg", type: "cats", breed: "Абисинска котка" },
    { id: 7, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/cat_brown_burmese_400x378_0.jpg", type: "cats", breed: "Бурманска котка" },
    { id: 8, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/cat_burmilla_400x378_0.jpg", type: "cats", breed: "Бурмила" },
    { id: 9, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/cat_devonrex_400x378_0.jpg", type: "cats", breed: "Девън рекс" },
    { id: 10, imageSrc: "https://www.purina.bg/sites/g/files/mcldtz1386/files/2018-02/cat_korat_400x378_0.jpg", type: "cats", breed: "Корат" },
  ];
  constructor(
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.petType = this.route.snapshot.params['type'];

    if (this.petType === "dogs") {
      this.pets = this.pets.filter(pet => pet.type === this.petType);
    } else if (this.petType === "cats") {
      this.pets = this.pets.filter(pet => pet.type === this.petType);
    }
  }

}
