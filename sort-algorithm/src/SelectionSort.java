import java.util.Arrays;

/*
Author: Ziqi Tan
*/
public class SelectionSort {

	public static void selectionSort(int nums[]) {
		int N = nums.length;
		// Do N - 1 times of loops
		for( int i = 0; i <= N - 2; i++ ) {			
			int index = i;  // find the minimum
			for( int j = i; j < N; j++ ) {
				if( nums[j] < nums[index] ) {
					index = j;
				}
			}
			// swap
			int temp = nums[index];
			nums[index] = nums[i];
			nums[i] = temp;
		}
	}
	
	public static void main(String[] args) {
		int[] nums = new int[] {2, 1, 3, 5, 4, 9, 15, 11};
		selectionSort(nums);
		System.out.println(Arrays.toString(nums));
	}

}
