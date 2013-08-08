class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> elems;
    vector<int> aux;
    vector<vector<int> > res;
        
    if (n == 0 || k == 0) return res;
    if (k > n) return res;
        
        
    //initialize two arrays
    for (int i = 0; i < n; i++) {
      elems.push_back(i+1);
    }
    for (int i = 0; i < k; i++) {
      aux.push_back(i+1);
    }
        
    //insert sentinel value
    aux.push_back(n+1);
    aux.push_back(0);
        
    while (true) {
      res.push_back(vector<int>(aux.begin(), aux.begin() + k));
            
      int j = 0;
      while (aux[j] + 1 == aux[j+1]) {
	aux[j] = j + 1;
	j += 1;
      }
            
      if (j == k) break;
            
      aux[j] += 1;
    }
        
    return res;
  }
};




