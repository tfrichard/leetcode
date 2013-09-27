class Solution {
public:
  bool isPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.size() == 0) return true;
        
    string str;
    for (char c : s) {
      if (isalnum(c)) {
	if (isalpha(c))
	  str.push_back(tolower(c));
	else
	  str.push_back(c);
      }
    }
        
    int i = 0;
    int j = str.size() - 1;
    while (i < j) {
      if (str[i] == str[j]) {
	i++, j--;
      } else 
	return false;
    }
        
    return true;
  }
};
