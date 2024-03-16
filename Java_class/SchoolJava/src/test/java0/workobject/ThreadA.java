package test.java0.workobject;

public class ThreadA extends Thread {
    private WorkObject workObject;

    public ThreadA(WorkObject workObject){
        setName("ThreadA");
        this.workObject=workObject;
    }

    @Override
    public void run() {
        for(int i=0; i<5; i++){
            workObject.methodA();
        }
    }
}
