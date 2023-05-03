package ex.java9.phone;

public class Phone {
    String owner;

    Phone(String owner){
        this.owner=owner;
    }
    void turnOn(){
        System.out.println("폰 전원을 켭니다.");
    }

    void turnOff(){
        System.out.println("폰 전원을 끝니다.");
    }
}
