class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int>> res(n, vector<int>(n,0));
        
    if (n == 0) return res;
        
    int num = 1, limit = n * n;
    int off = 0;
    while (n > 1 && num <= limit) {
      int i = off, j = off;
      for (; j < off + n - 1; j++) {
	res[i][j] = num++;
      }
            
      for (; i < off + n - 1; i++) {
	res[i][j] = num++;
      }
            
      for (; j > off; j--) {
	res[i][j] = num++;
      }
            
      for (; i > off; i--) {
	res[i][j] = num++;
      }
            
      off += 1;
      n -= 2;
    }
        
    if (n == 1 && num <= limit) {
      res[off][off] = limit;
    }
        
    return res;
  }
};


