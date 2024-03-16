package ex.java7;

public class ArrayCopy {
    public static void main(String[] args) {
        String[] old = {"a", "b", "c"};

        String[] str = new String[5];

        System.arraycopy(old, 0, str,
                0, old.length);

        for(int i=0; i<str.length; i++){
            System.out.println(str[i]);
        }
    }
}
