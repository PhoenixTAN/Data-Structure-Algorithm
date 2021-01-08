#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /**方法一：暴力法
 // nums表示输入数组首地址
 // numsSize表示数组长度
 // target表示两数之和的值
 // 函数返回两个加数所构成的数组的首地址**/
 /**
int* twoSum(int* nums, int numsSize, int target) {
    int a = 0;
    int b = 0;
    int i = 0, j = 0;
    static int resultNums[2];
    /**__SerializerHelper__.inl:10:10: runtime error: load of null pointer of type 'const int' **/
    /** 这里说返回了空的指针 **/
    /** 因为函数返回后，会消除临时变量，所以resultNums[]会被清除 **/
    /** 这里加上static就能通过了 **
    for( i = 0; i <= numsSize - 1; i++ ) {
        a = nums[i];
        for( j = i + 1; j <= numsSize - 1; j++ ) {
            b = nums[j];
            if( b == target - a ) {
                resultNums[0] = a;
                resultNums[1] = b;
                printf( "%d %d\n", a, b );
                resultNums[0] = i;
                resultNums[1] = j;
            }
        }
    }
    return resultNums;
}**/

/**方法二：哈希表
    //既然target为两数之和，
    //那么就可以用其中一个数作为索引，另一个数作为查找结果

**/
int* twoSum(int* nums, int numsSize, int target) {
    int myHashTable[10000];
    static int resultNums[2];
    int

    int i = 0;
    for( i = 0; i <= numsSize - 1; i++ ) {
        nums[i]
    }


    return resultNums;
}

int main()
{
    int nums[10000];
    int target = 0;
    int numsSize = 0;

    scanf( "%d", &numsSize );

    int i = 0;
    for( i = 0; i <= numsSize - 1; i++ ) {
        scanf( "%d", &nums[i] );
    }

    scanf( "%d", &target );

    twoSum( nums, numsSize, target );

    return 0;
}
