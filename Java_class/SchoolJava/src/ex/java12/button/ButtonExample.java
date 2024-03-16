package ex.java12.button;

public class ButtonExample {
    public static void main(String[] args) {
        Button btnOk=new Button();

        class OkListener implements Button.ClickListener{

            @Override
            public void onClick() {
                System.out.println("오케이 버튼을 클릭했ㅅ다");
            }
        }

        btnOk.setClickListener(new OkListener());
        btnOk.click();

        Button btnCancel = new Button();

        class CancelListener implements Button.ClickListener{

            @Override
            public void onClick() {
                System.out.println("취소버튼을 클릭했다");
            }
        }
        btnCancel.setClickListener(new CancelListener());
        btnCancel.click();
    }
}
