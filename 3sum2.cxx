class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > res;
    if (num.size() < 3) return res;
        
    sort(num.begin(), num.end());
    vector<vector<int> > pairs;
    for (int i = 0; i < num.size() - 2; i++) {
      pairs.clear();
      vector<int> tmp;
      if (twoSum(num, i+1, pairs, (-1) * num[i])) {
	for (vector<vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
	  tmp.push_back(num[i]);
	  for (vector<int>::iterator intIt = it->begin(); intIt != it->end(); intIt++) {
                        
	    tmp.push_back(*intIt);
	  }
                    
	  if (find(res.begin(), res.end(), tmp) == res.end())
	    res.push_back(tmp);
	  tmp.clear();
	}
                
      }
    }
    return res;
  }
    
private:
  bool twoSum(vector<int> &num, int begin, vector<vector<int> > &res, int target) {
    int end = num.size() - 1;
    vector<int> tmp;
    bool flag = false;
    while (begin < end) {
      if (num[begin] + num[end] == target) {
	tmp.push_back(num[begin]);
	tmp.push_back(num[end]);
	res.push_back(tmp);
	tmp.clear();
	begin++;
	flag = true;
      } else if (num[begin] + num[end] < target) {
	begin++;
      } else {
	end--;
      }
    }
    return flag;
  }
};
