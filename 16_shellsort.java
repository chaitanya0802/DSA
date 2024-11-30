import java.util.Arrays;

public class ShellSort {
    
    public void sort(int arr[]) {
        int n = arr.length;
        
        // Start with a large gap, then reduce the gap
        for (int gap = n / 2; gap > 0; gap /= 2) {
            
            // Perform insertion sort on elements separated by gap
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                
                arr[j] = temp;
            }
        }
    }
    
    public static void main(String args[]) {
        int arr[] = {12, 34, 54, 2, 3};
        ShellSort shellSort = new ShellSort();
        shellSort.sort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
