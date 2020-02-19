import java.time.Period;
import java.util.*;

public class Main {
	public class Car {
		private String registrationNumber;
		
		private String brand;
		
		private Date arrivalDate;
		
		private Date departureDate;
		
		public String getRegistrationNumber() {
			return this.registrationNumber;
		}
		
		public void setRegistrationNumber(String registrationNumber) {
			this.registrationNumber = registrationNumber;
		}
		
		public String getBrand() {
			return this.brand;
		}
		
		public void setBrand(String brand) {
			this.brand = brand;
		}
		
		public Date getArrivalDate() {
			return this.arrivalDate;
		}
		
		public void setArrivalDate(Date arrivalDate) {
			this.arrivalDate = arrivalDate;
		}
		
		public Date getDepartureDate() {
			return this.departureDate;
		}
		
		public void setDepartureDate(Date departureDate) {
			this.departureDate = departureDate;
		}
		
		Car(String registrationNumber, String brand) {
		  this.setBrand(brand);
		  this.setRegistrationNumber(registrationNumber);
		  this.arrivalDate = new Date();
		}
		
		public void leave(Parking parking) {
		 ArrayList<Car> cars = parking.getCars();
		 int index = 0;
		   
		 for (int i = 1; i < cars.size(); i ++) {
		  if(cars.get(i).getRegistrationNumber() == this.registrationNumber) {
		   index = i;
		  }
		 }
		   
		 parking.cars.remove(index);
		}
	}
	
	public class Parking {
		ArrayList<Car> cars;
		
		Parking() {
			this.cars = new ArrayList();
		}
		
		void addCar(Car car) {
			this.cars.add(car);
		}
		
		ArrayList<Car> getCars() {
			return this.cars;
		}
		
		int getNumberOfCars() {
			return this.cars.size();
		}
		
		// int calcStayedHours(Car car) {
			// Period period = new Period(car.arrivalDate, car.departureDate);
			// return period.getHours();
		// }
		
		double getMoneyForParking() {
			this.calcStayedHours(car)
		}
	}
	
	public static void main(String args[]) {
	  System.out.println("ss");
	  Parking parking = new Parking();
	  
	  Car car_1 = new Car("B 1111 BB", "Peugeot");
	  Car car_2 = new Car("B 1112 BB", "Mercedes");
	  
	  parking.addCar(car_1);
	  parking.addCar(car_2);
	  
	  car_1.leave(parking);
	 }
}
