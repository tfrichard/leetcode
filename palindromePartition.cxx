class Solution {
public:
  vector<vector<string>> partition(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<string>> res;
    vector<string> elem;
    partitionImpl(s, 0, elem, res);
    return res;
  }
    
  void partitionImpl(const string& s, int i, vector<string>& elem, vector<vector<string>> &res) {
    if (i == s.size()) {
      res.push_back(elem);
      return;
    }
        
    for (int j = i; j < s.size(); j++) {
      if (is_palindrome(s, i, j)) {
	elem.push_back(s.substr(i, j - i + 1));
	partitionImpl(s, j + 1, elem, res);
	elem.pop_back();
      }
    }
  }
    
  bool is_palindrome(const string& s, int i, int j){
    while (i < j) {
      if (s[i] == s[j]) {
	i++, j--;
      } else return false;
    }
    return true;
  }
};

