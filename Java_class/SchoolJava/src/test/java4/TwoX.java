package test.java4;

public class TwoX {

    public static void main(String[] args) {
        int k;
        for (int i = 1; i < 11; i++) {
            for (int j = 1; j < 11; j++) {
                k=4*i+5*j;
                if(k==60){
                    System.out.println("("+i+","+j+")");

                }
            }
        }

    }
}
