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
		// �ݹ鷵��
		if( left > right ) {
			return ;
		}
		
		int pivot = array[left];
		
		while( left < right ) {
			// ���ұ��ҵ���һ����pivotС��Ԫ��
			while( left < right && array[right] >= pivot ) {
				right--;
			}
			// ����
			if( left < right ) {
				int temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
			// ������ҵ�һ����pivot���Ԫ��
			while( left < right && array[left] <= pivot ) {
				left++;
			}
			// ����
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
