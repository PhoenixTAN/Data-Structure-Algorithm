import java.util.Arrays;

/*
Author: Ziqi Tan
*/
public class MergeSort {
	
	public static void mergeSort(int[] array) {
		int[] extraSpace = new int[array.length];
		divide(array, extraSpace, 0, array.length - 1);
	}
	
	private static void divide(int[] array, int[] extraSpace, int left, int right) {
		if( left < right ) {
            int mid = (left+right)/2;
            divide(array, extraSpace, left, mid);  // 左边归并排序，使得左子序列有序
            divide(array, extraSpace, mid+1, right);  // 右边归并排序，使得右子序列有序
            conquer(array, extraSpace, left,mid, right);  // 将两个有序子数组合并操作
        }		
	}
	
	private static void conquer(int[] array, int[] extraSpace, int left, int mid, int right) {
		int i = left;   // 左序列指针
        int j = mid + 1;   // 右序列指针
        int t = 0;       // 临时数组指针
        while (i <= mid && j <= right){
            if(array[i] <= array[j]){
            	extraSpace[t++] = array[i++];
            }
            else {
            	extraSpace[t++] = array[j++];
            }
        }
        while( i <= mid ) {// 将左边剩余元素填充进temp中
        	extraSpace[t++] = array[i++];
        }
        while( j <= right ) { // 将右序列剩余元素填充进temp中
        	extraSpace[t++] = array[j++];
        }
        t = 0;
        
        // 将temp中的元素全部拷贝到原数组中
        while(left <= right){
            array[left++] = extraSpace[t++];
        }
	}

	public static void main( String[] args ) {
		
		int[] array = new int[] {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
		mergeSort(array);
		System.out.println(Arrays.toString(array));
	}
}
