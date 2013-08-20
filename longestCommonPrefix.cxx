class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string res = "";
    if (strs.size() == 0) return res;
    if (strs.size() == 1) return strs[0];
        
    sort(strs.begin(), strs.end());
        
    string tmp = strs[0];
    for (int i = 0; i < tmp.size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
	if (strs[j][i] != tmp[i]) return res;
      }
      res.push_back(tmp[i]);
    }
        
    return res;
  }
};
