package ch06;
//count는 공유하는 자원이지만,
//생성된 쓰레드별로 counter인스턴스를 가지고 있다.
//동기화 블럭은 쓰레드간 동기화가 아닌, 한 쓰레드 내 동기화만 지원한다.
//모니터가 하나의 쓰레드의 동기화만 지원한다.
public class SynchExample4 {
    static class Counter{ //static으로 선언된 클래스는 static으로 선언된 변수나 메소드만 접근이 가능하다.
        public static int count = 0; //공유자원
        public void increment() {
            synchronized (this){ //동기화 선언, 쓰레드간 동기화가 아니라 객체 자신만 동기화 시킨다.
                Counter.count++;
            }

        }
    }
    static class MyRunnable implements Runnable {
        Counter counter;

        public MyRunnable(Counter counter) {
            this.counter = counter;
        }

        @Override
        public void run() {
            for (int i = 0; i < 10000; i++) {
                counter.increment();
            }
        }
    }

    public static void main(String[] args) throws Exception{
        Thread[] threads = new Thread[5];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(new MyRunnable(new Counter()));
            threads[i].start();
        }
        for (int i = 0; i < threads.length; i++) {
            threads[i].join();
        }
        System.out.println("counter = " + Counter.count);
    }
}
