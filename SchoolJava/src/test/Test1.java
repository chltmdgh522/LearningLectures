package test;

public interface Test1 {
    int a = 1;
    int b = 1;

    public void show1();

    default void show() {
        System.out.println("a");
    }
    static void show2(){
        System.out.println("a");
    }
}

