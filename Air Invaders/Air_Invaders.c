//
//  main.c
//  Air Invaders
//
//  Created by Ahmed Sheaira on 11/09/2022.
//

#include <stdio.h>
#include <stdlib.h>

// Max Plane Function gives how many planes we can protect from landing
int maxPlanes(int startHeight_count, int* startHeight, int descentRate_count, int* descentRate) {
    // max = maximum element in startHeight[] - 1
    // no_nine = number of planes prevented from landing
    // count = number of planes prevented from landing
    int max = 0, count = 0, flag, min_index, no_nine, i, j, k, l, m;
    
    // Loop for find maximum element in startHeight
    for (i=0 ; i<startHeight_count ; i++) {
        if (max < startHeight[i]) {
            max = startHeight[i];
        }
    }
    
    // increment max because it can used to denote number of planes which either landed or prevented from landing
    max++;
    
    do {
        // flag is used to check if any plane landed or not
        // flag = 0 : means plane didnot landed
        // flag = 1 : means at least one plane landed
        flag = 0;
        no_nine = 0;
        
        // loop for update the value of every second in startHight[]
        for (j=0 ; j<startHeight_count ; j++) {
            if (startHeight[j] != max) {
                startHeight[j] = startHeight[j] - descentRate[j];
            }
        }
        
        // loop for check the number of landed planes
        // if there are planes which has landed then flag = 1
        for (k=0 ; k<startHeight_count ; k++) {
            if (startHeight[k] <= 0) {
                startHeight[k] = max;
                flag = 1;
            }
        }
        
        // Check for landed any plane or not
        if (flag == 0) {
            min_index = 0;
            // if there is not any plane landed, then this loop will select plane which is at minimum height
            for (l=0 ; l<startHeight_count ; l++) {
                if (startHeight[min_index] > startHeight[l]) {
                    min_index = l;
                }
            }
            // plane at minimum height will be shoot down, so set its value = max
            startHeight[min_index] = max;
        }
        
        // it count number of planes shoot down till now
        count++;
        // loop will find out how many planes landed or shoot down, simply by counting number of max in startHeight[]
        for (m=0 ; m<startHeight_count ; m++) {
            if (startHeight[m] == max) {
                no_nine++;
            }
        }
    
    } while (no_nine != descentRate_count);
    
    // return the counter which consist of number of planes which has shot down
    return count;
}

int main() {
    int startHight[10] = {1, 3, 5, 4, 8};
    int descentRate[10] = {1, 2, 2, 1, 2};
    int c = maxPlanes(5, startHight, 5, descentRate);
    printf("%d\n", c);
    return 0;
}
