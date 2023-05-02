package test.java4;

import java.util.Random;

public class RandomMath {
    public static void main(String[] args) {
        int cnt=0;
        while (true) {
            cnt++;
            int a = (int) (Math.random() * 6) + 1;
            int b = (int) (Math.random() * 6) + 1;
            Random rd=new Random();
           int c= rd.nextInt(1)+1;

           System.out.println(c);
            if(a+b==5){
                System.out.println(cnt);
                System.out.println(a+","+b);
                break;
            }


        }
    }
}
