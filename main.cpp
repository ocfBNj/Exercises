#include <stdio.h>

int main() {
    int i, j;
    while (1) {
        for (i = 0; i < 1000; i++)
            ;
        for (j = 0; j < 1000000000; j++) printf("enter kernel mode running.");
    }
}
