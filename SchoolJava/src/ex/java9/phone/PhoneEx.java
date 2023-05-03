package ex.java9.phone;

public class PhoneEx {
    public static void main(String[] args) {
        Phone phone=new Phone("d");

        SmartPhone smartPhone= new SmartPhone("승호");
        smartPhone.turnOn();
        smartPhone.turnOff();
        smartPhone.internetSearch();
    }
}
