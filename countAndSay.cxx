class Solution {
public:
  string countAndSay(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string res = "1";
    if (n == 1) {
      return res;
    }
        
    for (int i = 2; i <= n; i++) {
      res = parseStr(res);
    }
        
    return res;
  }
    
  string parseStr(string str) {
    string res ="";
    int len = str.size();
    int count = 0;
    char say = str[0];
    int i = 0;
    while (i < len) {
      while (str[i] == say && i < len) {
	count++;
	i++;
      }
      res.push_back(count + '0');
      res.push_back(say);
      if (i == len) break;
      say = str[i];
      count = 0;
    }
    return res;
  }
};
