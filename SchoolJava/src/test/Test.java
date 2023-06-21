package test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;

public class Test {
    String b=null;
    class Test1{
        String a=null;
        public void run(){};
        public static void main(String[] args) {
            Test t= new Test();
            Test.Test1 t2 =t.new Test1(){
                public void run(){
                    System.out.println(a+t.b);
                }
            };
        }
    }



}
