#include "stdio.h"
int fun_add (int a, int b, int c, int d);

int fun_add(int a, int b, int c, int d) {
    return a + b + c + d;
}
int main(void)
{
    int ret;
    ret = fun_add(1, 4, 5, 6);
    printf("Result = %d\n", ret);
    for(;;);
    return 0;
}

