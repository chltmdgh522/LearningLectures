package test.java11.problem8;

import java.io.IOException;

public class FEX {
    public static void main(String[] args) {
        try(FileWriter fw=new FileWriter("csh")){
         fw.write("gd");
        } catch (IOException e) {
            System.out.println("dd");
        }
    }
}
