#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> /* signal() */
#include <sys/types.h>
#include <sys/wait.h> /* wait() */

/* prototype fungsi penanganan signal */

void sig_handler();

int main(){
pid_t pid;
int i;
signal(SIGCHLD, sig_handler);

/* install signal handler baru untuk SIGCHLD */
pid = fork(); /* buat proses baru */
switch (pid) {
  case -1: perror("fork"); /* proses fork() gagal */
    exit(EXIT_FAILURE); /* exit jika gagal */
  case 0: /* ini proses child */
    printf("CHILD: Hello parent\n");
    sleep(3); /* tunda selama 3 detik */
    exit(EXIT_SUCCESS); /* akhiri proses child */
  default : /* ini proses parent */
    printf("PARENT: Hello child\n");

    for (i=1; i<=5; i++) {
      printf("PARENT: %d\n", i);
      sleep(1); /* tunda selama 1 detik */
    }

    printf("parent Selesai.\n");
    exit(EXIT_SUCCESS); /* akhiri proses parent */
  }
}

/* ini definisi fungsi penanganan signal */
void sig_handler(){
  printf("child Selesai.\n");
}
