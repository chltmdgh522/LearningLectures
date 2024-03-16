package test.java0.printerthread2;

public class PrintThread  extends Thread{


    @Override
    public void run() {
        try {
            while (true) {
                System.out.println("실행");
                Thread.sleep(1); //일시 정지
            }
        }catch (InterruptedException e){}

        System.out.println("리소스 정리");
        System.out.println("실행 종료");
    }
}
