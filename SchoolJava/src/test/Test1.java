package test;

public class Test1 implements AutoCloseable {

    public Test1(String file){
        System.out.println(file+"파일을 연다");
    }
    public void write(String text){
        System.out.println(text+"문자를 연다");
    }

    public void close() throws Exception{
        System.out.println("a");
    }
}

