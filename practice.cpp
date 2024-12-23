class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        // Edge case: if the array is already sorted
        while (left < right && arr[left] <= arr[left + 1]) {
            left++;
        }
        if (left == n - 1) return 0;

        // Find the right boundary of the last sorted segment
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        // Compute the minimum length to remove
        int answer = min(n - left - 1, right);

        // Try to merge the sorted segments
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                answer = min(answer, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return answer;
    }
};
