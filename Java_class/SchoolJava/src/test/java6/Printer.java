package test.java6;

public class Printer {

    public boolean println(boolean x){
        return x;
    }

    public int println(int x){
        return x;
    }

    public double println(double x){
        return x;
    }

    public String println(String x){
        return x;
    }

    public static void main(String[] args) {
        Printer printer = new Printer();
        printer.println(1);
    }
}
