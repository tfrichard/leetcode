class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int res = 0;
    int m = matrix.size();
    if (m == 0) return res;
    int n = matrix[0].size();
    if (n == 0) return res;
    int dp[m][n];
    fill(&dp[0][0], &dp[m][0], 0);
        
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (matrix[i][j] == '1') {
	  dp[i][j] = j > 0 ? dp[i][j-1] + 1 : 1;
	}
      }
    }
        
    int min = dp[0][0];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	min = dp[i][j];
	int k = i;
	while (k >= 0) {
	  if (min > dp[k][j]) min = dp[k][j];
	  res = max(res, min * (i - k + 1));
	  k--;
	}
      }
    }
        
    return res;
  }
};





