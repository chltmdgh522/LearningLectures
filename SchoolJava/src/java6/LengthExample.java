package java6;

public class LengthExample {
    public static void main(String[] args) {
        String ssn="950624123023";
        int length=ssn.length();
        if(length==13){
            System.out.println("주민등록번호 자릿수 맞습니다.");
        }
        else{
            System.out.println("주민등록번호 자릿수 틀립니다.");
        }

        String[] str=new String[3];
        str[0]="java";
        str[1]="jav";
        System.out.println(str[0]=str[1]);
    }
}
