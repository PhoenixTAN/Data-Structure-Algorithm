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
            divide(array, extraSpace, left, mid);  // ��߹鲢����ʹ��������������
            divide(array, extraSpace, mid+1, right);  // �ұ߹鲢����ʹ��������������
            conquer(array, extraSpace, left,mid, right);  // ����������������ϲ�����
        }		
	}
	
	private static void conquer(int[] array, int[] extraSpace, int left, int mid, int right) {
		int i = left;   // ������ָ��
        int j = mid + 1;   // ������ָ��
        int t = 0;       // ��ʱ����ָ��
        while (i <= mid && j <= right){
            if(array[i] <= array[j]){
            	extraSpace[t++] = array[i++];
            }
            else {
            	extraSpace[t++] = array[j++];
            }
        }
        while( i <= mid ) {// �����ʣ��Ԫ������temp��
        	extraSpace[t++] = array[i++];
        }
        while( j <= right ) { // ��������ʣ��Ԫ������temp��
        	extraSpace[t++] = array[j++];
        }
        t = 0;
        
        // ��temp�е�Ԫ��ȫ��������ԭ������
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
