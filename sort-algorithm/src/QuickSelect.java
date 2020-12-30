import java.util.Arrays;
import java.util.Random;

/*
Author: Ziqi Tan
*/
public class QuickSelect {

	static int[] nums;

	public static void swap(int a, int b) {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}

	public static int partition(int left, int right, int pivot_index) {
		int pivot = nums[pivot_index];
		// 1. move pivot to end
		swap(pivot_index, right);
		int store_index = left;
		System.out.println("Before move: " + Arrays.toString(nums));
		// 2. move all smaller elements to the left
		for (int i = left; i <= right; i++) {
			if (nums[i] < pivot) {
				swap(store_index, i);
				store_index++;
			}
		}

		// 3. move pivot to its final place
		swap(store_index, right);
		
		System.out.println("pivot=" + pivot);
		System.out.println(Arrays.toString(nums));
		
		return store_index;
	}

	public static int quickselect(int left, int right, int k_smallest) {
		/*
		 * Returns the k-th smallest element of list within left..right.
		 */

		if (left == right) // If the list contains only one element,
			return nums[left]; // return that element

		// select a random pivot_index
		Random random_num = new Random();
		int pivot_index = left + random_num.nextInt(right - left);
		
		pivot_index = partition(left, right, pivot_index);

		// the pivot is on (N - k)th smallest position
		if (k_smallest == pivot_index) {
			return nums[k_smallest];
		}		
		// go left side
		else if (k_smallest < pivot_index) {
			System.out.println(k_smallest + "<" + pivot_index);
			return quickselect(left, pivot_index - 1, k_smallest);
		}		
		// go right side
		System.out.println(k_smallest + ">" + pivot_index);
		return quickselect(pivot_index + 1, right, k_smallest);
	}

	public static int findKthSmallest(int[] _nums, int k) {
		nums = _nums;
		int size = nums.length;
		// kth largest is (N - k)th smallest
		// k starts from zero
		return quickselect(0, size - 1, k);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] array = new int[] {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
		System.out.println("Array: " + Arrays.toString(array));
		System.out.println("Result: " + findKthSmallest(array, 2));
		System.out.println(Arrays.toString(array));
		

	}

}
