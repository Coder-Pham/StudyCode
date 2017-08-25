public class BinarySearch() {
	int binarySearch(int[] a, int x) {
        int start = 0;
        int end = a.length - 1;
        int mid = (start + end) / 2;
        int res = -1;
        while (start != end) {
            if (x < a[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = (start + end) / 2;
            if (a[mid] == x) {
                res = mid;
                break;
            }
        }
        return res;
    }
	
	int lowerBound(int[] a, int x) {
        int low = 0;
        int high = a.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (x <= a[mid]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

    int upperBound(int[] a, int x) {
        int low = 0;
        int high = a.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (x >= a[mid]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
}