package test.java0.workobject;

public class WorkObject {
    public synchronized void methodA(){
        Thread thread=Thread.currentThread();
        System.out.println(thread.getName() +": A실행");
        notify();
        try{
            wait();
        }catch (InterruptedException e){
            System.out.println(e);
        }
    }

    public synchronized void methodB(){
        Thread thread=Thread.currentThread();
        System.out.println(thread.getName() +": B실행");
        notify();
        try{
            wait();
        }catch (InterruptedException e){
            System.out.println(e);
        }
    }
}
