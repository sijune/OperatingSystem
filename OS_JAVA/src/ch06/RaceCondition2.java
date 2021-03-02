package ch06;

class RunnableTwo implements Runnable {
    static int count = 0;

    @Override
    public void run() {
        for (int i = 0; i < 1000000; i++) {
            count++;
        }
    }
}

//쓰레드마다 인스턴스를 생성, 그러나 클래스변수를 두 인스턴스간 공유를 한다.
public class RaceCondition2{
    public static void main(String[] args) throws Exception {
        RunnableTwo run1 = new RunnableTwo();
        RunnableTwo run2 = new RunnableTwo();
        Thread t1 = new Thread(run1);
        Thread t2 = new Thread(run2);
        t1.start();
        t2.start();
        t1.join(); // 자식 스레드의 종료를 기다려준다.
        t2.join();
        System.out.println("Result : " + RunnableTwo.count);
    }
}
