package java6;

public class Car {

    String company = "현대자동차";
    String model;
    String color;
    int maxSpeed;
    Car() {
    }
    Car(String model) {
        this.model = model;
        this.color="은색";
    }

}

class CarExample {

    public static void main(String[] args) {
        Car car1 = new Car("d");

        System.out.println(car1.color);


    }
}