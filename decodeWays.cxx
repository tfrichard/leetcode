class Solution {
public:
  int numDecodings(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.size() == 0)
      return 0;
        
    if (s.size() == 1) {
      return s[0] == '0' ? 0 : 1;
    }
        
    if (s[0] == '0') return 0;
        
    int len = s.size();
    int dp[len+1];
    dp[0] = 1;
    dp[1] = 1;
        
    for (int i = 2; i < len+1; i++) {
      if (s[i-2] == '0') {
	if (s[i-1] == '0') return 0;
	else dp[i] = dp[i-1];
      } else if (s[i-2] == '1') {
	if (s[i-1] == '0') dp[i] = dp[i-2];
	else dp[i] = dp[i-2] + dp[i-1];
      } else if (s[i-2] == '2') {
	if (s[i-1] == '0') {
	  dp[i] = dp[i-2];
	} else if (s[i-1] > '6') {
	  dp[i] = dp[i-1];
	} else {
	  dp[i] = dp[i-2] + dp[i-1];
	}
      } else {
	if (s[i-1] == '0') return 0;
	else dp[i] = dp[i-1];
      }
    }
        
    return dp[len];
  }
};
