//recursive version
class Solution {
public:
  int minDistance(string word1, string word2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int m = word1.size();
    int n = word2.size();
        
    int res = minDistanceImpl(word1, word2, m, n);
    return res;
  }
    
  int minDistanceImpl(string w1, string w2, int s1, int s2) {
    if (s1 == 0) return s2;
    if (s2 == 0) return s1;
        
    if (w1[s1-1] == w2[s2-1]) {
      return minDistanceImpl(w1, w2, s1 - 1, s2 - 1);
    } else {
      return min(minDistanceImpl(w1, w2, s1 - 1, s2), 
		 min(minDistanceImpl(w1, w2, s1, s2 - 1), minDistanceImpl(w1, w2, s1 - 1, s2 - 1))) + 1;
    }
  }
};

//dynamic programming
class Solution {
public:
  int minDistance(string word1, string word2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int m = word1.size();
    int n = word2.size();
        
    if (m == 0) return n;
    if (n == 0) return m;
        
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for (int i = 1; i < m + 1; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j < n + 1; j++) {
      dp[0][j] = j;
    }
        
    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
	if (word1[i-1] == word2[j-1]) {
	  dp[i][j] = dp[i-1][j-1];
	} else {
	  dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
	}
      }
    }
        
    return dp[m][n];
  }
};
