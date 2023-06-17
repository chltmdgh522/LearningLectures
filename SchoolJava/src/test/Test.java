package test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;

public class Test {
    public static void main(String[] args) {
        String[] arr={"1", "12"};
        for(int i=0; i<= arr.length; i++){
        try{
            int value=Integer.parseInt(arr[i]);
        }catch (ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }catch (Exception e){
            System.out.println(e);
        }
        }
    }
}
