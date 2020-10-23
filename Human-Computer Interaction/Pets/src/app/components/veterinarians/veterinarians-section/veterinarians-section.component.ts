import { Component, OnInit } from '@angular/core';
import { VeterinarianModel } from '../../shared/models/VeterinarianModel';

@Component({
  selector: 'app-veterinarians-section',
  templateUrl: './veterinarians-section.component.html',
  styleUrls: ['./veterinarians-section.component.scss']
})
export class VeterinariansSectionComponent implements OnInit {
  veterinarians: VeterinarianModel[] = [
    { name: "Анна Мирчева", address: "ул. Панорама №24", phone: "0897278609", town: "варна" },
    { name: "Ваня Тодорова", address: "ж.к. Кайсиева градина", phone: "0890495169", town: "варна" },
    { name: "Венцислав Димитров", address: "к.к. Св.Св. Константин и Елена", phone: "0897585265", town: "варна" },
    { name: "Адра Христова", address: "ул. Суходолско езеро 5", phone: "0887797330", town: "софия" },
    { name: "Алекс Борисов", address: "Вет. клиника 'Есковет' ж.к. Надежда ул. Христо Стоянов 61-63", phone: "0884767559", town: "софия" },
    { name: "Албена Пенева-Витанова", address: "ж.к. Красно село ул. Княгина Клементина 28", phone: "0888230192", town: "софия" },
    { name: "Адриан Георгиев", address: "ж.к. Тракия срещу блок 83", phone: "0876410969", town: "пловдив" },
    { name: "Ангел Иванов", address: "бул. Марица 27", phone: "0989457353", town: "пловдив" },
    { name: "Благовест Атанасов", address: "Пазарджишко шосе №93, 4 км.", phone: "0878762403", town: "пловдив" },
  ];

  constructor() { }

  ngOnInit(): void {
  }

}
