package ch06;

public class SynchExample2 {
    static class Counter{ //static으로 선언된 클래스는 static으로 선언된 변수나 메소드만 접근이 가능하다.
        public static int count = 0; //공유자원
        synchronized public static void increment() {
            count++;
        } //동기화 선언
    }
    static class MyRunnable implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < 10000; i++) {
                Counter.increment();
            }
        }
    }

    public static void main(String[] args) throws Exception{
        Thread[] threads = new Thread[5];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(new MyRunnable());
            threads[i].start();
        }
        for (int i = 0; i < threads.length; i++) {
            threads[i].join();
        }
        System.out.println("counter = " + Counter.count);
    }
}
