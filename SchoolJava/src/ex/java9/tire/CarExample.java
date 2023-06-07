package ex.java9.tire;

public class CarExample {
    public static void main(String[] args) {
        Car car = new Car();
        car.tire = new HankookTire();
        car.run();

        Tire tire = new HankookTire();
        tire.roll();
    }
}
