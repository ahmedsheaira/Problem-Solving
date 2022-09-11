//
//  main.c
//  Count bits
//
//  Created by Ahmed Sheaira on 11/09/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[10], a[10];

int* countBits(int n) {
    int count = 0, len = (log2(n) + 1), i = 1, j = 0, k;
    while (n) {
        if (n&1) {
            count++;
            a[j] = len;
            j++;
        }
        len--;
        n >>= 1;
    }
    arr[0] = count;
    for (k = j-1 ; k>=0 ; k--) {
        arr[i] = a[k];
        i++;
    }
    return (arr);
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *ptr = countBits(n);
    int size = ptr[0] + 1;
    for (i=0 ; i<size ; i++) {
        printf("%d\n", ptr[i]);
    }
    return 0;
}
