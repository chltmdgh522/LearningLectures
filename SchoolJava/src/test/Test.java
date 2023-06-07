package test;

import java.util.Random;

public class Test {
    void end() {
    }

    class Chat {
        void start() {
        }
    }

    int a = 4;

    void show() {
        int a = 4;
        Chat chat = new Chat() {
            @Override
            void start() {
                System.out.println(a);
            }
        };

    }
}

class A {
    public static void main(String[] args) {

    }
}
