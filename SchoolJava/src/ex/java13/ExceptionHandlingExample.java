package ex.java13;

public class ExceptionHandlingExample {
    public static void main(String[] args) {
        String[] array={"100","1oo"};
        for(int i=0; i<= array.length; i++){
            try{
                int value=Integer.parseInt(array[i]);
            }catch(ArrayIndexOutOfBoundsException e){
                System.out.println("배열인덱스 초과됨"+e.getMessage());
            }catch (Exception e){
                System.out.println("실행문제");
            }
        }
    }
}
