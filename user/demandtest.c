#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    // Reserve 30 pages of heap and get pointer to start
    char *p = (char*)sbrk(4096 * 30);  

    printf("Before touching pages: %d\n", countpp());

    
    for(int i = 0; i < 30; i++){
        p[i * 4096] = 1;   // trigger page fault
    }

    printf("After touching pages: %d\n", countpp());

    exit(0);
}
