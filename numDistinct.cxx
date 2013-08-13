class Solution {
public:
  int numDistinct(string S, string T) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int res = numDistinctImpl(S, T, S.size(), T.size());
    return res;
  }
    
  int numDistinctImpl(string S, string T, int si, int tj) {
    if (tj == 0) return 1;
        
    if (si == 0) return 0;
        
    if (S[si-1] == T[tj-1]) return numDistinctImpl(S, T, si - 1, tj - 1) 
			      + numDistinctImpl(S, T, si - 1, tj);
    else return numDistinctImpl(S, T, si - 1, tj);
  }
};
