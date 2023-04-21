package test.java5;

import java.util.Scanner;

public class Student {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int student_cnt=0;

            System.out.println("------------------------------------------------");
            System.out.println("1.학생수 | 2.점수입력 | 3.점수리스트 | 4.분석 | 5.종료");
            System.out.println("------------------------------------------------");
            System.out.print("선택> ");
            int num = s.nextInt();

            if(num==1){
                System.out.print("\n학생수>");
                student_cnt=s.nextInt();
            }

            System.out.println(student_cnt);

    }
}
