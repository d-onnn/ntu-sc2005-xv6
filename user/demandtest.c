#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    sbrk(4096 * 30);   // reserve 30 pages

    printf("Before touching pages: %d\n", countpp());

    char *p = (char*)sbrk(0);

    for(int i = 0; i < 30; i++){
        p[i * 4096] = 1;   // trigger page fault
    }

    printf("After touching pages: %d\n", countpp());

    exit(0);
}
