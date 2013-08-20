class Solution {
public:
  int lengthOfLastWord(const char *s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s == NULL) return 0;
    int len = strlen(s);
    int lastLen = 0;
    int i = len - 1;
    bool flag = false;
        
    while (i >= 0) {
      if (isspace(*(s+i))) {
	if (flag) return lastLen;
	else i--;
      }
      else {
	lastLen++;
	if (!flag) flag = true;
	i--;
      }
    }
        
    if (flag) return lastLen;
    else return 0;
  }
};
