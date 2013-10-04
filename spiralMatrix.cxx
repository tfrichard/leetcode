class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> res;
    int m = matrix.size();
    if (m == 0) return res;
    int n = matrix[0].size();
        
    int off = 0;
    while (m > 1 && n > 1) {
      int i = off, j = off;
      for (j = off; j < off + n - 1; j++) {
	res.push_back(matrix[i][j]);
      }
            
      for (i = off; i < off + m - 1; i++) {
	res.push_back(matrix[i][j]);
      }
            
      for (; j > off; j--) {
	res.push_back(matrix[i][j]);
      }
            
      for (; i > off; i--) {
	res.push_back(matrix[i][j]);
      }
            
      off += 1;
      m -= 2;
      n -= 2;
    }
        
    if (m == 1) {
      for (int i = off; i <= off + n - 1; i++) {
	res.push_back(matrix[off][i]);
      }
      return res;
    }
        
    if (n == 1) {
      for (int i = off; i <= off + m - 1; i++) {
	res.push_back(matrix[i][off]);
      }
      return res;
    }
        
    return res;
  }
};

