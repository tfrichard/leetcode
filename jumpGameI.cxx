class Solution {
public:
  bool canJump(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n <= 1) return true;
        
        
    int cur_max = A[0];
    for (int i = 0; i <= cur_max; i++) {
      if (i + A[i] >= n - 1) return true;
            
      if (i + A[i] > cur_max)
	cur_max = i + A[i];
    }
        
    return false;
  }
};
