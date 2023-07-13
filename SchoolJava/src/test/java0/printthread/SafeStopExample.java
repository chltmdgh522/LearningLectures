package test.java0.printthread;

import test.java0.printerthread2.PrintThread;

public class SafeStopExample {
    public static void main(String[] args) {
        PrintThread thread =new PrintThread();
        thread.start();

        try{
            Thread.sleep(3000);
        }catch (InterruptedException e){}
    //thread.setStop(true);
    }

}
