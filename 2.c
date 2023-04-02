#include <stdio.h>

int main() {

    int primo, i, j;

    for (i = 2;; i++) {
        primo = 1; 
        for (j = 2; j < i; j++)
        {
            if (i % j == 0) {
                primo = 0; 
                break;
            }
        }
        if (primo == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}