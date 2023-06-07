package test.abstract1;

public class SmartPhone extends Phone {
    SmartPhone(String owner) {
        super(owner);
        System.out.println(owner);
    }

    void inter(){
        System.out.println("검색할게");
    }
}
