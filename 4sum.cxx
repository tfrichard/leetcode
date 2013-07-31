class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > res;
    if (num.size() < 4) return res;
        
    sort(num.begin(), num.end());
    //find all 4 combinations out of n
    int n = num.size();
    vector<int> comb(6); //aux array should be two elems larger than combination k
    vector<int> elems(n);
    //intialize auxiliary array and elements array
    for (int i = 0; i < 4; i++) {
      comb[i] = i;
    }
    comb[4] = n;
    comb[5] = 0;
        
    for (int i = 0; i < n; i++) {
      elems[i] = i;
    }
        
    while (true) {
      int j = 0;
      //visit current combiantion and test if satisfy target
      vector<int> test;
      if (num[comb[0]] + num[comb[1]] + num[comb[2]] + num[comb[3]] == target) {
	test.push_back(num[comb[0]]);
	test.push_back(num[comb[1]]);
	test.push_back(num[comb[2]]);
	test.push_back(num[comb[3]]);
	if (find(res.begin(), res.end(), test) == res.end())
	  res.push_back(test);
      }
            
      while (comb[j] + 1 == comb[j+1]) {
	comb[j] = j;
	j += 1;
      }
            
      if (j == 4) break;
      comb[j] += 1;
    }
        
    return res;
  }
};
