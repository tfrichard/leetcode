class Solution {
public:
  int maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n <= 0) return 0;
    int res = A[0];
        
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += A[i];
      if (sum > res) res = sum;
      if (sum < 0) sum = 0;
    }
        
    return res;
  }
};

//divide and conquer version
class Solution {
public:
  int maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n == 0) return 0;
    return maxSubArrayImpl(A, 0, n);
  }
    
  int maxSubArrayImpl(int A[], int begin, int end) {
    if (begin == end) return -99999999;
        
    if (begin == end - 1) return A[begin];
        
    int mid = begin + (end - begin) / 2;
    int m1 = maxSubArrayImpl(A, begin, mid);
    int m2 = maxSubArrayImpl(A, mid + 1, end);
    int m3 = A[mid];
    int k = mid;
    int left = 0, right = 0;
    int sum = 0;
    while (--k >= begin) {
      sum += A[k];
      if (sum > left) left = sum;
    }
    k = mid;
    sum = 0;
    while (++k < end) {
      sum += A[k];
      if (sum > right) right = sum;
    }
    m3 += left + right;
        
    return max(m1, max(m2, m3));
  }
};

