#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t start, end;
    start = clock();

    end = clock();
    printf("\n\n  %5.2f seg.\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}
