import java.util.Arrays;

/*
Author: Ziqi Tan
*/
public class QuickSort {
	
	public static void quickSort(int[] array) {
		quickSortHelper(array, 0, array.length - 1);
	}
	
	private static void quickSortHelper(int[] array, int i, int j) {
		
		int left = i;
		int right = j;
		// 递归返回
		if( left > right ) {
			return ;
		}
		
		int pivot = array[left];
		
		while( left < right ) {
			// 从右边找到第一个比pivot小的元素
			while( left < right && array[right] >= pivot ) {
				right--;
			}
			// 交换
			if( left < right ) {
				int temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
			// 从左边找第一个比pivot大的元素
			while( left < right && array[left] <= pivot ) {
				left++;
			}
			// 交换
			if( left < right ) {
				int temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
		}
		quickSortHelper(array, i, left - 1);
		quickSortHelper(array, left + 1, j);		
	}

	public static void main( String[] args ) {
		
		int[] array = new int[] {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
		quickSort(array);
		System.out.println(Arrays.toString(array));
		
	}
}
