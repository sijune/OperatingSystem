package ch04;

public class ThreadExample4 {
    public static void main(String[] args) {
        Runnable task = () -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Hello, Lambda Runnable!");
            }
        };
        Thread thread = new Thread(task);
        thread.start();
        try {
            thread.join();
        } catch (InterruptedException ie) {
            System.out.println("I'm interrupt");
        }
        System.out.println("Hello, My Child");
    }
}