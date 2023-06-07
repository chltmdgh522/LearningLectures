package ex.java9.abstract1;

public abstract class Phone {
    String owner;
    Phone(String owner){
        this.owner=owner;
    }
    void turnOn(){
        System.out.println("폰 전원 킬게");
    }

    void turnOff(){
        System.out.println("폰 전원 끌게");
    }
}
