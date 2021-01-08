#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3[20000];
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    double median = 0.0;

    
    while( p1 <= nums1Size - 1 && p2 <= nums2Size - 1 ) {
        if( nums1[p1] < nums2[p2] ) {
            nums3[p3] = nums1[p1];
            p1++;
            p3++;
        }
        else{
            nums3[p3] = nums2[p2];
            p2++;
            p3++;
        }
    }

    if( p1 <= nums1Size - 1 ) {
        while( p1 <= nums1Size - 1 ) {
            nums3[p3] = nums1[p1];
            p1++;
            p3++;
        }
    }
    else if( p2 <= nums2Size - 1 ) {
        while( p2 <= nums2Size - 1 ) {
            nums3[p3] = nums2[p2];
            p2++;
            p3++;
        }
    }

    int i = 0;
    for( i = 0; i <= p3 - 1; i++ ) {
        printf( "%d ", nums3[i] );
    }

    if( p3 % 2 == 0 ) {
        
        median = ( nums3[p3/2] + nums3[p3/2-1] ) / 2.0;
    }
    else{
        median = nums3[p3/2];
    }
    printf( "median: %lf", median );

    return median;
}

int main()
{
    int m = 6;
    int n = 4;
    int nums1[] = { 1, 3, 5, 7, 9, 11 };
    int nums2[] = { 2, 3 ,4, 5 };

    findMedianSortedArrays( nums1, m, nums2, n );

    return 0;
}
