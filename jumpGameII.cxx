class Solution {
public:
  int jump(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n <= 1) return 0;
        
    int maxhop = A[0];
    int start = 0;
    int end = maxhop;
    int step = 0;
        
    int i = start;
        
    while (start < maxhop) {
      i = start;
      if (i + A[i] >= n - 1) return step + 1;
      step++;
            
      while (i <= end) {
	if (i + A[i] >= n - 1) {
	  return step + 1;
	}
	if (i + A[i] > maxhop) {
	  maxhop = i + A[i];
	  start = i;
	}
	i++;
      }
            
      if (start >= maxhop) return -1;
            
      end = maxhop;
    }
        
    return -1;
  }
};
