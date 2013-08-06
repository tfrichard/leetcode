class Solution {
public:
  //actually it's a fabonacci problem
  int climbStairs(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int f0 = 1, f1 = 1;
    if (n == 0 || n == 1) return 1;
        
    int res = 0;
    for (int i = 2; i <= n; i++) 
      {
	res = f0 + f1;
	f0 = f1;
	f1 = res;
      }
        
    return res;
  }
};
