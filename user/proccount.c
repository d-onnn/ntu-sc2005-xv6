#include"kernel/types.h"
#include"kernel/stat.h"
#include"user/user.h"

int
main(void)
{
  int n = getproccount();
  printf("Active processes: %d\n",n);
  exit(0);
}

