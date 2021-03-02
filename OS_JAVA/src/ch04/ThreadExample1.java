package ch04;

class MyThread1 extends Thread{
    @Override
    public void run() {
        try {
            while(true){
                System.out.println("Hello");
                Thread.sleep(500);
            }
        } catch(InterruptedException ie){
            System.out.println("I'm interrupted");

        }
    }
}
class ThreadExample1 {
    public static void main(String[] args) {
        MyThread1 thread = new MyThread1();
        thread.start();
        System.out.println("Hello, My Child");
    }
}