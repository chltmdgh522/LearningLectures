package ex.java12.nonameinterface;

public class HomeExample {
    public static void main(String[] args) {
        Home home = new Home();
        home.run1();
        home.run2();
        home.run3(new RemoteControl() {
            @Override
            public void turnOn() {
                System.out.println("d");
            }

            @Override
            public void turnOff() {
                System.out.println("dd");
            }
        });
    }
}
