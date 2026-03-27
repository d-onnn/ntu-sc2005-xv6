#include "kernel/types.h"
#include "user/user.h"

//part2 of excercise2
//int main() {
    //int *p = 0;
    // *p = 1;
    //exit(0);
//}


int main() {
    char *p = sbrk(0);   // end of heap
    p[1] = 'A';          // access beyond allocated memory
    exit(0);
}
