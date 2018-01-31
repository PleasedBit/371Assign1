#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(){

  char * path = "/cshome/ldmcdona/test/magic";

  struct stat fileStat;

  stat(path, &fileStat);

  printf("Last file modification: %s", ctime(&fileStat.st_mtime));

  if(strcmp(ctime(&fileStat.st_mtime), "Wed Jan 31 13:26:24 2018\n") != 0){
    printf("Modified\n");
  }else{
    printf("Not Midified\n");
  }
  
  return 0;
}

