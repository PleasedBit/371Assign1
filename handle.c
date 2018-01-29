#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

static void newHandler(int signo){
  switch (signo) {
  case SIGUSR1:
    printf("Working\n");
  }
}

int main(){

  clock_t start = clock();
  
  struct sigaction new_action;
  new_action.sa_handler = &newHandler;
  sigaction(SIGUSR1, &new_action, NULL);

  while(1){
    if(((clock() - start) / CLOCKS_PER_SEC) > 2){
      kill(getpid(), 10);
      start = clock();
    }
  }

  return 0;
}
