package ex.java9.abstract1;

public class SmartPhone extends Phone{
    SmartPhone(String owner) {
        super(owner);
    }

    void inter(){
        System.out.println("검색할게");
    }
}
