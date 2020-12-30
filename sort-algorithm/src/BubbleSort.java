import java.util.Arrays;

/*
Author: Ziqi Tan
*/
public class BubbleSort {
	
	public static void bubbleSort(int nums[]) {
		int N = nums.length;
		// Do N - 1 times of the nested loop,
		// which means bubbling N - 1 times
		for( int i = 0; i < N - 1; i++ ) {
			for( int j = 0; j < N - 1 - i; j++ ) {
				if( nums[j] > nums[j+1] ) {
					int temp = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = temp;
				}
			}			
		}		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = new int[] {2, 1, 3, 5, 4, 9, 15, 11};
		bubbleSort(nums);
		System.out.println(Arrays.toString(nums));
	}
}
