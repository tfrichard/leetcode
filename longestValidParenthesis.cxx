class Solution {
public:
  int longestValidParentheses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.size() < 2) return 0;
    stack<int> index;
    int res = 0;
    int n = s.size();
    int last = -1;
        
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
	index.push(i);
      } else {
	if (index.empty()) {
	  last = i;
	} else {
	  index.pop();
	  if (index.empty()) {
	    res = max(res, i - last);
	  } else {
	    res = max(res, i - index.top());
	  }
	}
      }
    }
        
    return res;
  }
};
