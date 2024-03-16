package ex.java9.pc;

public class ChildExample {

    public static void main(String[] args) {


        Parent parent= new Child();
        parent.method1();
        parent.method2();

        Child child =new Child();
        child.method1();
    }

}
