package test;

import java.util.Random;

public class Test {
    public static void main(String[] args) {
        int a = (int) ((Math.random() * 6) + 1);
        Random rd= new Random();
        int b =rd.nextInt(6)+1;
        System.out.println(a);


    }
}
