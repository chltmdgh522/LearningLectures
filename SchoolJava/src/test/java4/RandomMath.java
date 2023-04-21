package test.java4;

public class RandomMath {
    public static void main(String[] args) {
        int cnt=0;
        while (true) {
            cnt++;
            int a = (int) (Math.random() * 6) + 1;
            int b = (int) (Math.random() * 6) + 1;
            if(a+b==5){
                System.out.println(cnt);
                System.out.println(a+","+b);
                break;
            }


        }
    }
}
