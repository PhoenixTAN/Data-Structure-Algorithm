# Quick sort and quick select

Leetcode 215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```
Example 2:
```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```

参考：
https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm

## 方法一： 先来耳熟能详的 最简洁的快排 本题暴力解法

```java
import java.util.Arrays;
import java.util.Random;

/*
Author: Ziqi Tan
*/
public class QuickSort {
	
	Random random = new Random();
	
	public void quickSort(int[] array) {
		partition(array, 0, array.length - 1);
	}
	
	private void partition(int[] array, int leftIndex, int rightIndex) {
		if ( leftIndex > rightIndex ) {
			return ;	//递归出口
		}
		// 后面还需要用到leftIndex和rightIndex
		// 所以换个变量名
		int left = leftIndex;
		int right = rightIndex;
		
		// 随机选一个枢轴
		int pivotIndex = random.nextInt(right-left+1) + left;	
		int pivot = array[pivotIndex];	// 枢轴的值存起来
		swap(array, pivotIndex, left);	// 枢轴放到最左边
		
		// 双指针法 进行一轮快排，使得枢轴左边的数都比枢轴小，枢轴右边的数，都比枢轴大
		while( left < right ) {
			while( left < right && array[right] >= pivot ) right--;		// 从右边找到第一个比枢轴小的
			while( left < right && array[left] <= pivot ) left++;	// 从左边找第一个比枢轴大的
			if ( left < right ) swap(array, left, right);	// 把刚刚找到的两个数交换
		}
		swap(array, left, leftIndex);	// 交换后，left的位置就是枢轴的位置

        // 为什么如果枢轴在最左边，就要从右边开始找第一个比枢轴小的
        // 9 1 2 5 4 3 6 7 10 8

		
		// divide and conquer
		partition(array, 0, left - 1);
		partition(array, left + 1, rightIndex);	
	}
	
	private void swap(int[] array, int index1, int index2) {
		int temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
	}

	public static void main( String[] args ) {
		
		int[] array = new int[] {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
		Random random = new Random();
		for ( int i = 0; i < array.length; i++ ) {
			array[i] = random.nextInt(5);
		}
		new QuickSort().quickSort(array);
		System.out.println(Arrays.toString(array));
		
	}
}
```
时间复杂度: O(Nlog_N)

## 再讲讲快速选择
```java
class Solution {
    Random random = new Random();

    public int findKthLargest(int[] nums, int k) {
        quickSelect(nums, nums.length - k, 0, nums.length - 1);
        return nums[nums.length - k];
    }

    /*
    *   @params nums: int[] 原数组
    *   @params k: int 第k大的数，实际上第k大，就是(nums.length - k)小
    */
    private void quickSelect(int[] nums, int k, int left, int right) {
        // 按照快速排序的思路
        // 枢轴左边的数总比枢轴小，枢轴右边的数总比枢轴大
        // 那么顺数第k个数，如果在枢轴右边，那么说明第k个数比枢轴大
        // 应该继续往右边找，否则继续往左边找
        // 如果第k个数恰好是枢轴，直接返回
        int pivotIndex = partition(nums, left, right);
        if ( pivotIndex == k ) {
            return ;
        }

        if ( pivotIndex < k ) {
            quickSelect(nums, k, pivotIndex + 1, right);
        }
        else {
            quickSelect(nums, k, left, pivotIndex - 1);
        }
    }

    private int partition(int[] nums, int leftIndex, int rightIndex) {
        int randomIndex = random.nextInt(rightIndex-leftIndex+1) + leftIndex;  // we can make the pivot random
        swap(nums, randomIndex, leftIndex);
        int pivot = nums[leftIndex];     // 把枢轴放在最左边

        int left = leftIndex;
        int right = rightIndex;
        // 左右指针
        while( left < right ) {
            // 从右边找到比枢轴小的
	    while( left < right && nums[right] >= pivot ) right--;
            // 从左边找到比枢轴大的
	    while( left < right && nums[left] <= pivot ) left++;
            // 两者交换
	    if( left < right ) swap(nums, left, right);
	}
        swap(nums, left, leftIndex);    // 把枢轴放到左右指针交汇的位置
        return left;   // 此时i的位置，就是枢轴的位置
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
时间复杂度：O(N)因为

## 还有一种次优的做法：维护长度为k的优先队列（最小堆）
时间复杂度: O(Nlog_k)
