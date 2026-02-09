#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p1[2], p2[2];
  char buf[6];

  pipe(p1);
  pipe(p2);

  if(fork() == 0){
    // Implement the Child code here
    //close unused pipes
    close(p1[1]);  //child does not write to p1
    close(p2[0]);   //child does not read from p2
    //read msg from parent
    read(p1[0], buf, 5);
    buf[5] = '\0';
    printf("Child Recieve: %s\n", buf);
    write(p2[1], "world", 5);
    exit(0);
  } else {
    // Implement the Parent code here
    //close unused pipes
    close(p1[0]);  //parent does not write to p1
    close(p2[1]);   //parent does not read from p2
    //send msg to child
    write(p1[1], "hello", 5);
    //read reply from child
    read(p2[0], buf, 5);
    buf[5] = '\0';
    printf("Parent Recieved: %s\n", buf);
    
    wait(0);
    exit(0);


  }
}
