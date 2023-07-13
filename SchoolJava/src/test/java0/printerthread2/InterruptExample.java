package test.java0.printerthread2;

public class InterruptExample {
    public static void main(String[] args) {
        PrintThread thread= new PrintThread();
        thread.start();

        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            System.out.println(e);
        }

        thread.interrupt();
    }
}
