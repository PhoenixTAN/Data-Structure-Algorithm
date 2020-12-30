#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int iMin = 0;
    int iMax = nums1Size;
    int median_location = ( nums1Size + nums2Size + 1 ) / 2;
    int i = 0;
    int j = 0;
    int max_left = 0;
    int min_right = 0;

    static double median = 0.0;

    if( nums1Size > nums2Size ) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tmp = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tmp;
    }

    while( iMin <= iMax ) {
        i = ( iMin + iMax ) / 2;
        j = median_location - i; // 确保i,j将两个数组等份切成left part and right part

        if( i < iMax && nums2[j-1] > nums1[i] ) {
            // i is too small.
            iMin = i + 1;
            printf( "i=%d j=%d\n", i, j );
        }
        else if( i > iMin && nums1[i-1] > nums2[j] ) {
            // i is too big.
            iMax = i - 1;
            printf( "i=%d j=%d\n", i, j );
        }
        else {
            // i is perfect.
            printf( "i=%d j=%d\n", i, j );
            max_left = 0;
            if( i == 0 ) {
                max_left = nums2[j-1];
            }
            else if( j == 0 ) {
                max_left = nums1[i-1];
            }
            else {
                max_left = (nums1[i-1] > nums2[j-1]) ? nums1[i-1] : nums2[j-1];
            }

            // 奇数个数直接返回中位数
            if( ( nums1Size + nums2Size ) % 2 == 1 ) {
                median = max_left;
                printf( "%lf", median );
                return median;
            }

            min_right = 0;
            if( i == nums1Size ) {
                min_right = nums2[j];
            }
            else if( j == nums2Size ) {
                min_right = nums1[i];
            }
            else{
                min_right = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
            }
            //偶数个数就要算一下
            median = (max_left + min_right) / 2.0;
            printf( "%lf", median );
            return median;
        }
    }

    return median;
}

int main()
{
    //int m = 9;
    //int n = 7;
    //int nums1[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
    //int nums2[] = {  2,3,4,5,     10,          16, 18 };

    int m = 2;
    int n = 1;
    int nums1[] = { 1, 3 };
    int nums2[] = { 2 };

    //int m = 2;
    //int n = 2;
    //int nums1[] = { 1, 2 };
    //int nums2[] = { 3, 4 };

    findMedianSortedArrays( nums1, m, nums2, n );

    return 0;
}
