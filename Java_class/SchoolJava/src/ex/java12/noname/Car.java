package ex.java12.noname;

public class Car {
    Tire tire1 =new Tire();
    Tire tire2=new Tire(){
        @Override
        public void roll(){
            System.out.println("객체1 굴러간다.");
        }
    };

    public void run1(){
        tire1.roll();
        tire2.roll();
    }

    public void run2(){
        Tire tire3=new Tire(){
            @Override
            public void roll() {
                System.out.println("객체2 굴러간다.");
            }
        };
        tire3.roll();
       }

    public void run3(Tire tire){
        tire.roll();
    }

}
