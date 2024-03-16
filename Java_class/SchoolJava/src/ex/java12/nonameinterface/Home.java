package ex.java12.nonameinterface;

public class Home {
    RemoteControl rc= new RemoteControl() {
        @Override
        public void turnOn() {
            System.out.println("핕드를 킵니다.");
        }

        @Override
        public void turnOff() {
            System.out.println("핕드를 끕니다.");
        }
    };
    public void run1(){
        rc.turnOn();
        rc.turnOff();
    }

    public void run2(){
        RemoteControl rc=new RemoteControl() {
            @Override
            public void turnOn() {
                System.out.println("로컬을 킵니다.");
            }

            @Override
            public void turnOff() {
                System.out.println("로컬을 끕니다.");
            }
        };
        rc.turnOn();
        rc.turnOff();
    }
    public void run3(RemoteControl rc){
        rc.turnOn();
        rc.turnOff();
    }
}
