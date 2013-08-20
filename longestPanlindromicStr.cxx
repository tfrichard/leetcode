class Solution {
public:
  string longestPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string res = "";
    if (s.size() == 0) return res;
    if (s.size() == 1) return s.substr(0);
    int n = s.size();
    int max = 0;
    int start = 0;
        
    for (int i = 0; i < n; i++) {
      int begin = i;
      int end = i + 1;
      int len = 0;
      while (begin - len >= 0 && begin + len <= n - 1) {
	if (s[begin - len] == s[begin + len]) {
	  len += 1;
	  if (max < 2 * len - 1) {
	    max = 2 * len - 1;
	    start = begin - len + 1;
	  }
	  //begin++;
	} else break;
      }
            
      len = 0;
      while (begin >= 0 && end <= n - 1) {
	if (s[begin] == s[end]) {
	  len++;
	  if (max < len * 2) {
	    max = len * 2;
	    start = begin;
	  }
	  begin--, end++;
	} else break;
      }
            
    }
        
    res = s.substr(start, max);
    return res;
  }
};
