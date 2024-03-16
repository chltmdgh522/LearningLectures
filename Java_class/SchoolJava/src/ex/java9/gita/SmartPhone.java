package ex.java9.gita;

public class SmartPhone extends Phone{
    public boolean wifi;

    public SmartPhone(String model){
        this.model=model;
        this.color=color;
    }

    public void setWifi(boolean wifi){
        this.wifi=wifi;
        System.out.println("와이파이 상태를 변경하겠습니다.");
    }
    public void internet(){
        System.out.println("인터넷에 연결합니다.");
    }
}
