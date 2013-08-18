class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function    
    if (s3.size() != s1.size() + s2.size()) return false;
        
    if (s1.size() == 0) return s3 == s2;
    if (s2.size() == 0) return s3 == s1;
        
    return isInterleaveImpl(s1, s2, s3, 0, 0, 0);
        
        
  }

  //recursive solution, time exceeded  
  bool isInterleaveImpl(string s1, string s2, string s3, int i, int j, int k) {
    if (i == s3.size() && j == s1.size() && k == s2.size()) return true;
    if (j == s2.size() && k == s3.size()) return false;
        
    if (j == s2.size()) return s3.substr(i) == s1.substr(k);
    if (k == s1.size()) return s3.substr(i) == s2.substr(j);
        
        
    while (i < s3.size()) {
      if (s3[i] == s1[k] && s3[i] != s2[j]) {
	k++;
      } else if (s3[i] == s2[j] && s3[i] != s1[k]) {
	j++;
      } else if (s3[i] == s2[j] && s3[i] == s1[k]){
	return isInterleaveImpl(s1, s2, s3, i + 1, j + 1, k) || 
	  isInterleaveImpl(s1, s2, s3, i + 1, j, k + 1);
      } else {
	return false;
      }
      i++;
    }
        
    return true;
  }
     
  
};
