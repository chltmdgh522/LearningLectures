package test.java11.problem8;

import java.io.IOException;

public class FileWriter implements AutoCloseable{

    public FileWriter(String filePath) throws IOException {
        System.out.println(filePath + "엽니다.");
    }

    public void write(String data) throws IOException{
        System.out.println("data");
    }
    @Override
    public void close() throws IOException {

    }
}
