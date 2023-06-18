package test;

public interface Test1 {
    int a = 1;
    int b = 1;

    public void show1();

    default void show() {
        System.out.println("a");
        show2();
    }
    static void show2() {
        System.out.println("a");
    show3();
    }

    private static void show3(){

    }
}

