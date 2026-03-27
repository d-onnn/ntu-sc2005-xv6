#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
    int vp, pp;

    vp = countvp();
    pp = countpp();
    printf("Before sbrk: vp=%d pp=%d\n", vp, pp);

    sbrk(4096 * 5);   // grow by 5 pages

    vp = countvp();
    pp = countpp();
    printf("After sbrk: vp=%d pp=%d\n", vp, pp);

    exit(0);
}
