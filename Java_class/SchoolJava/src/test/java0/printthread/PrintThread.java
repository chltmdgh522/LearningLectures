package test.java0.printthread;

public class PrintThread extends Thread{


    @Override
    public void run() {
        try {
            while (true) {
                System.out.println("실행");
                Thread.sleep(2);
            }
        }catch (InterruptedException e){}

        System.out.println("리소스 정리");
        System.out.println("실행 종료");
    }
}
