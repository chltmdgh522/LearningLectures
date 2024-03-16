package test.java0.beepPrintExample;

public class ThreadNameExample {
    public static void main(String[] args) {
        Thread mainThread = Thread.currentThread();
        System.out.println(mainThread.getName());

        for(int i=0; i<3; i++){
            Thread threadA=new Thread(){
                @Override
                public void run() {
                    System.out.println(getName());
                }
            };
            threadA.start();
        }

        Thread thread=new Thread(){
            @Override
            public void run() {
                System.out.println(getName());
            }
        };
        thread.setName("chltmdgh");
        thread.start();

    }
}
