package ex.java12.noname;

public class CarExample {
    public static void main(String[] args) {
        Car car=new Car();
        car.run1();
        car.run2();
        car.run3(new Tire(){
            @Override
            public void roll(){
                System.out.println("객체3 이굴러간다.");
            }
        });
    }
}
