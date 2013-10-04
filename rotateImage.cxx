class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = matrix.size();
    if (n == 0 || n == 1) return;
        
    int loop_cnt  = (n + 1) / 2;
    int off = 0;
    while (loop_cnt > 0) {
      vector<int> tmp(matrix[off].begin() + off, matrix[off].end() - off - 1);
            
      int i = off + n - 1, j = off;
      for (; j < i; j++) {
	matrix[off][j] = matrix[i - j + off][off];
      }
            
      for (; j > off; j--) {
	matrix[j][off] = matrix[i][j];
      }
            
      for (; j < i; j++) {
	matrix[i][i-j + off] = matrix[j][i];
      }
            
      for (; j > off; j--) {
	matrix[i-j+off][i] = tmp[i-j];
      }
            
      off += 1;
      n -= 2;
      loop_cnt -= 1;
    }
  }
};



