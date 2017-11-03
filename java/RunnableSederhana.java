public class RunnableSederhana implements Runnable {
      private int hitungMundur = 3;

          public void run() {
                    while (true) {
                      System.out.println(Thread.currentThread().getName() + " : " + hitungMundur);
                      if (--hitungMundur == 0)
                      return;
                          }
                        }
    public static void main(String[] args) {
      for (int i = 1; i <= 3; i++) {
          // Buat thread baru dan jalankan
     Thread a = new Thread(new RunnableSederhana(), "Thread ke-" + i);
                   a.start();
          }
   }
}
