#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /**����һ��������
 // nums��ʾ���������׵�ַ
 // numsSize��ʾ���鳤��
 // target��ʾ����֮�͵�ֵ
 // ���������������������ɵ�������׵�ַ**/
 /**
int* twoSum(int* nums, int numsSize, int target) {
    int a = 0;
    int b = 0;
    int i = 0, j = 0;
    static int resultNums[2];
    /**__SerializerHelper__.inl:10:10: runtime error: load of null pointer of type 'const int' **/
    /** ����˵�����˿յ�ָ�� **/
    /** ��Ϊ�������غ󣬻�������ʱ����������resultNums[]�ᱻ��� **/
    /** �������static����ͨ���� **
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

/**����������ϣ��
    //��ȻtargetΪ����֮�ͣ�
    //��ô�Ϳ���������һ������Ϊ��������һ������Ϊ���ҽ��

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
