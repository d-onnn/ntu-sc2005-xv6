#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"

#define MAX 64


struct uproc {
  int pid;
  int state;
};

char*
state_string(int state)
{
  switch(state){
  case 0: return "UNUSED";
  case 1: return "SLEEPING";
  case 2: return "RUNNABLE";
  case 3: return "RUNNING";
  case 4: return "ZOMBIE";
  default: return "UNKNOWN";
  }
}

int
main(void)
{
  struct uproc procs[MAX];

  int n = getprocs(procs, MAX);

  printf("PID\tSTATE\n");

  for(int i = 0; i < n; i++){
    printf("%d\t%s\n", procs[i].pid,
           state_string(procs[i].state));
  }

  exit(0);
}
