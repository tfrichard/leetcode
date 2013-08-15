class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (needle == NULL || haystack == NULL) return NULL;
        
    if (strlen(haystack) < strlen(needle)) return NULL;
        
    int m = strlen(haystack);
    int n = strlen(needle);
        
    for (int i = 0; i <= m - n; i++) {
      int j = 0;
      for (j = 0; j < n; j++) {
	if (haystack[i+j] != needle[j]) {
	  break;
	}
      }
      if (j == n) return haystack + i;
    }
        
    return NULL;
  }
};
