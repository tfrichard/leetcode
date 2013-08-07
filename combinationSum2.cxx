class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > res;
    vector<int> sln;
    if (candidates.size() == 0) return res;
        
    sort(candidates.begin(), candidates.end());
    if (candidates[0] > target) return res;
       
    combSumImpl(res, candidates, 0, target, sln);
        
    return res;

  }
    
private:
  void combSumImpl(vector<vector<int> > &res, vector<int> &candidates, int i, int target, 
		   vector<int> sln) {       
        
        
    if (target == 0) {
      if (find(res.begin(), res.end(), sln) == res.end()) {
	res.push_back(sln);
      }
      return;
    }
        
    if (target < 0 || i >= candidates.size()) return;
    if (candidates[i] == 0) return;
        
    combSumImpl(res, candidates, i + 1, target, sln);
        
    if (target - candidates[i] >= 0) {
        
      sln.push_back(candidates[i]);
      combSumImpl(res, candidates, i + 1, target - candidates[i], sln);
            
    }
        
        
  }
};

