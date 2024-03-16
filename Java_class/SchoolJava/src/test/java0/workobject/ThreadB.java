package test.java0.workobject;

public class ThreadB extends Thread {
    private WorkObject workObject;

    public ThreadB(WorkObject workObject){
        setName("ThreadB");
        this.workObject=workObject;
    }

    @Override
    public void run() {
        for(int i=0; i<5; i++){
            workObject.methodB();
        }
    }
}
