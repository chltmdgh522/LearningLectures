package ex.java9;

public class SupersonicAirplaneExample {
    public static void main(String[] args) {
        SupersoniAirplane sa=new SupersoniAirplane();

        sa.takeOFf();
        sa.fly();
        sa.flyMode=SupersoniAirplane.SUPERSONIC;
        sa.fly();
        sa.flyMode=SupersoniAirplane.NORMAL;
        sa.fly();

    }
}
