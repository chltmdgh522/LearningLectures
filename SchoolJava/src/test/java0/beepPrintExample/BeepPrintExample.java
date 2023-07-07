package test.java0.beepPrintExample;

import java.awt.*;

public class BeepPrintExample {
    public static void main(String[] args) {
        Thread thread=new Thread() {
            @Override
            public void run() {
                System.out.println("g");
                Toolkit toolkit = Toolkit.getDefaultToolkit();
                for (int i = 0; i < 5; i++) {
                    toolkit.beep();
                    System.out.println("a");
                    try {
                        Thread.sleep(500);
                    } catch (Exception e) {
                    }

                }
            }
        };
        thread.start();
        System.out.println("d");
        System.out.println("e");
        for (int i = 0; i < 5; i++) {
            System.out.println("띵");
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }
        }
    }
}


/*   Toolkit toolkit = Toolkit.getDefaultToolkit();
        for (int i = 0; i < 5; i++) {
            toolkit.beep();
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }

        }
        for (int i = 0; i < 5; i++) {
            System.out.println("띵");
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }
        }*/

