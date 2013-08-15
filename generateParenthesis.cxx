class Solution {
public:
  vector<string> generateParenthesis(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int l = 0;
    int r = 0;
    vector<string> res;
    if (n == 0) return res;
    string str = "";
    genImpl(l, r, n, str, res);
    return res;
  }
    
  void genImpl(int l, int r, int n, string &str, vector<string> &res) {
    if (l >= n && r >= n) {
      res.push_back(str);
      return;
    }
        
    if (l < n) {
      str.push_back('(');
      //l++;
      genImpl(l + 1, r, n, str, res);
      str.pop_back();
    }
        
    if (r < n && r < l) {
      str.push_back(')');
      //r++;
      genImpl(l, r + 1, n, str, res);
      str.pop_back();
    }
  }
};




