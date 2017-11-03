#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
 
pthread_mutex_t bilangan_lock = PTHREAD_MUTEX_INITIALIZER;

int bilangan = 0;
pthread_t T0;

void *tambah(void *a){
  int i, j;
  pthread_mutex_lock(&bilangan_lock);
  for(i=0;i<20;i++){
    j=bilangan;
    j++;
    sleep(1);
    bilangan = j;
  }
  pthread_mutex_unlock(&bilangan_lock);
  return NULL;
}

int main() {
  int i,j;
  printf("Nilai Bilangan Awal = %i\n", bilangan);
  pthread_mutex_lock(&bilangan_lock);
  if(pthread_create(&T0, NULL, tambah, NULL) == -1)
//     error("thread tidak bisa dibuat");
  for(i=0;i<20;i++){
    j=bilangan;
    j++;
    sleep(1);
    bilangan = j;
  }
  pthread_mutex_unlock(&bilangan_lock);
  void* result;
  pthread_join(T0, &result);
  printf("Nilai Bilangan akhir = %i\n", bilangan);
  return 0;
}
