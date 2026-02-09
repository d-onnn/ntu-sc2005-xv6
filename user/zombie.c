// Create a zombie process that
// must be reparented at exit.

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  //print PID in a new line
  printf("Process ID: %d\n",getpid());
  if(fork() > 0)
    sleep(5);  // Let child exit before parent.
  exit(0);
}
