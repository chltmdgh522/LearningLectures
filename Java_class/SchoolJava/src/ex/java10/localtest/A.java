package ex.java10.localtest;

public class A {

    void useB(){
        class B{
            void show(){
                System.out.println("1");
            }

            static void show1(){
                System.out.println("2");
            }
        }

        B b =new B();
        b.show();
        B.show1();

    }
}


class B{
    public static void main(String[] args) {
        A a= new A();
        a.useB();
    }
}
