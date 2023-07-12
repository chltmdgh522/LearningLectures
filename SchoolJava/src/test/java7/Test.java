package test.java7;

import java.util.HashMap;
import java.util.Map;

public class Test {
    Map<String, Integer> map=new HashMap<>();
    public Test(){
        map.put("2",1);
    }

    public void show(){
        map.get("2");
    }
    public static void main(String[] args) {
        Test t = new Test();
        Integer integer = t.map.get("2");
    }

}
