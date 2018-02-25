/**
 * @author Nhat M. Nguyen
 * @date   25-02-18
**/


class MergeSort {
    /**
     * @param a     array
     * @param start index of the start position, inclusive
     * @param end   index of the end position, inclusive
     */
    public void sort(int[] a, int start, int end) {
        // If the length of the subarray is 1, it is already sorted.
        if (start < end) {
            int mid = (start + end) / 2;
            sort(a, start, mid);
            sort(a, mid + 1, end);
            merge(a, start, mid, end);
        }
    }

    /**
     * @param a     array
     * @param start index of the start position, inclusive
     * @param mid   index of the mid position;
     *              a[mid] belongs to the left part
     * @param end   index of the end position, inclusive
     */
    private void merge(int[] a, int start, int mid, int end) {
        // Create copies of the left and right subarrays
        int nLeft = mid - start + 1;
        int nRight = end - (mid + 1) + 1;
        int[] left = new int[nLeft + 1];
        int[] right = new int[nRight + 1];

        for (int i = 0; i < nLeft; i++) {
            left[i] = a[start + i];
        }
        for (int i = 0; i < nRight; i++) {
            right[i] = a[mid + 1 + i];
        }

        // Small trick: last element of each subarray is set to infinity
        left[nLeft] = Integer.MAX_VALUE;
        right[nRight] = Integer.MAX_VALUE;

        int i = 0;
        int j = 0;

        for (int k = start; k <= end; k++) {
            if (left[i] < right[j]) {
                a[k] = left[i];
                i++;
            }
            else {
                a[k] = right[j];
                j++;
            }
        }
    }
}
