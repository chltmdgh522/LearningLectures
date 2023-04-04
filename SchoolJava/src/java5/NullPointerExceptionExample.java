package java5;

public class NullPointerExceptionExample {
    public static void main(String[] args) {
        int[] intArray=null;
        String str=null;
        try{
            System.out.println(str.length());
        }catch (NullPointerException e){
            System.out.println(e);
        }
        String std=new String("d");


        int intValue=10;
        char charValue='A';
        double doubleValue=56.7;
        String strValue="a";
        double var=intValue;
        System.out.println("a"+var);
        String.valueOf(charValue);




    }
}
