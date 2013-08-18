class Solution {
public:
  bool canJump(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    if (n == 1)
      return true;

    int i , cur_max = 0 , target = n-1;

    for (i=0 ; i<n-1; ++i)
      {
	if (A[i] == 0 && cur_max < i+1)
	  return false;

	if (A[i] + i > cur_max)
	  {
	    cur_max = i + A[i];

	    if (cur_max >= target)
	      return true;
	  }
      }
    return false;
  }
};
