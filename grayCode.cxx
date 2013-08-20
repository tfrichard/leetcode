class Solution {
public:
  vector<int> grayCode(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> res;
        
    int sum = pow(2, n);
        
    for (int i = 0; i < sum; i++) {
      res.push_back(i ^ (i >> 1));    
    }
    return res;
  }
};
