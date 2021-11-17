#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
   
   printf("May the forking commence\n");
   int f1;
   int f2;

   f1 = fork();
   srand(time(NULL));

    // makes the second child process
   if(f1) {
       // to alternate the tiem slept by the processes
      rand();
      f2 = fork();
   }

    
   if (f1 && f2){
    int s;

	// waits till child has finished before parent process goes
    int child_pid = wait(&s);
	// to track the time slept by process
    int sleep_tracker = WEXITSTATUS(s);
	
	
    printf("\tCompleted child pid is %d \n", child_pid);
    printf("\tTime slept: %d secs\n",sleep_tracker);
    printf("Parent process finished\n");
    return 0;
  } else{
	  
     printf("Child pid : %d\n", getpid());
     // to get random number of seconds between [2,5]
     int sleepy_time = (rand() % (4)) + 2;
     // sleeps child process for random amount of seconds
     sleep(sleepy_time);
     printf("Child process %d finished\n", getpid());
     return sleepy_time;
  }

  return 0;
}