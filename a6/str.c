#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    int s = strcmp("abc","aabc");
    printf("%d\n", s);
    s = strcmp("bcd","abc");
    printf("%d\n", s);

    return 0;
}
