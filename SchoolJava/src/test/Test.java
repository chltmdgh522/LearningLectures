package test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;

public class Test {
    public static void main(String[] args) {
        try( Test1 test1=new Test1("승호")){

            test1.write("d");
        }catch(Exception e){
            System.out.println(e);
        }

    }

}
