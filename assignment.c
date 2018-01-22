#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <linux/inotify.h>

//Program by Liam McDonald
//With contents taken from: https://www.thegeekstuff.com/2010/04/inotify-c-program-example/

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

int main(){
  printf("Start\n");
  /* int period;
  scanf("%d", &period);
  char * path; 
  scanf("%s", path);

  struct tm *date;
  time_t raw;
  time( &raw );
  date = localtime( &raw );*/
  //date is now [Week day] [Month] [Day] [hour:minute:second] [year]
  //All we have to add is the MST in the print statement

  //[goto location given in path, or exit if path if a lie]

  //clock_t timer = clock();

  /*
  //[Save knowledge of directory] // currently only prints it?
  DIR *dir;
  struct dirent *dp;
  char * file_name;
  dir = opendir(".");
  while((dp = readdir(dir)) != NULL){
  if(!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")){
  }else{
  file_name = dp->d_name;
  printf("%c %s\n", file_name);
  }
  }
  */

  //[Report knowledge of directoyr and time]
  //printf(" // I don't know how to edit the print statement

  //[if time == period or signal == True]
  //[Show changes and update knowledge]

  int fd;
  int wd;
  int length, i = 0;
  char buffer[EVENT_BUF_LEN];
  fd = inotify_init();
  printf("flag1\n");
  if(fd < 0){
    perror("inotify_init");
  }
  printf("flag1.5\n");
  wd = inotify_add_watch(fd, "/home/user/Documents", IN_CREATE | IN_DELETE); //path
  printf("flag1.75\n");
  length = read(fd, buffer, EVENT_BUF_LEN);
  printf("flag2\n");
  if(length < 0){
    perror("read");
  }
  printf("flag3\n");
  while(i < length){
    printf("mark\n");
    struct inotify_event *event = (struct inotify_event *) &buffer[i];
    if(event->len){
      if(event->mask & IN_CREATE){
	if(event->mask & IN_ISDIR){
	  printf("New directory %s created.\n", event->name);
	}else{
	  printf("New file %s created.\n", event->name);
	}
      }else if(event->mask & IN_DELETE){
	if(event->mask & IN_ISDIR){
	  printf("Directory %s deleted.\n", event->name);
	}else{
	  printf("File %s deleted.\n", event->name);
	}
      }
    }
    i += EVENT_SIZE + event->len;
  }
  inotify_rm_watch(fd, wd);
  close(fd);

  return 0;
}
