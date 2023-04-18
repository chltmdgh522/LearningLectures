package java7;

class MemberService {
    String id;
    String passwd;

    public boolean login(String id, String passwd) {
        if (id.equals("hong") && passwd.equals("12345")) {
            return true;

        } else {
            return false;
        }
    }

    public void logout(String id) {
        System.out.println(id + "님이 로그라웃");
    }


}

public class MemberServiceTest {
    public static void main(String[] args) {
        MemberService memberService = new MemberService();
        boolean result = memberService.login("hong", "12345");
        if (result) {
            System.out.println("로그인됨");
            memberService.logout("hong");
        } else {
            System.out.println("잠ㄹ소됨");
        }
    }
}
