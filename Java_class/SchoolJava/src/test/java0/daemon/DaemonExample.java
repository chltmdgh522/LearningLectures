package test.java0.daemon;

import ex.java3.A;

public class DaemonExample {
    public static void main(String[] args) {
        AutoSaveThread autoSaveThread = new AutoSaveThread();
        autoSaveThread.setDaemon(true);
        autoSaveThread.start();

        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
        }
        System.out.println("메인 스레드 종료");
    }
}
