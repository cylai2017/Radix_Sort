
#include <stdio.h>

int* Radix_Sort(int* array, int length){
    int MAX = 100;                          // Upperbound
    int array_Index = 0, Radix = 1;           // radix = 1, 10, 100,...
    int buckets[length][length];   // buckets[The number of bucket][store the data]
    int count[length];     // record the number of data in each bucket
    
    while(Radix <= MAX){                  
        for(int i = 0; i < length; i++){
            int LSD = (int)((array[i]/Radix)) % 10;    // calculate LSD
            buckets[LSD][count[LSD]] = array[i];          // put the data into the corresponding bucket
            count[LSD]++;
        }
        Radix *= 10;                                     // update Radix：1->10, 10->100
        
        // Combination
        array_Index = 0;
        for(int j = 0; j < length; j++){         // Combine the data in bucket
            if(count[j] != 0){                        // Whether the bucket has the data or not
                for(int k =0 ; k < count[j]; k++){
                    array[array_Index++] = buckets[j][k];
                }
            }
            count[j] = 0;                             //  return to zero
        }
    }
    return array;
}
