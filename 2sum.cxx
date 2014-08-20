struct IndexPair {
  int val;
  int index;
};

bool operator < (IndexPair p1, IndexPair p2) {
  return p1.val < p2.val;
}

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<IndexPair> index_vec;
    for (int i = 0; i < numbers.size(); i++) {
      IndexPair pair;
      pair.val = numbers[i];
      pair.index = i+1;
      index_vec.push_back(pair);
    }
        
    sort(index_vec.begin(), index_vec.end());
        
    vector<int> res;
    if (numbers.size() < 2) return res;
        
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      int tmp = index_vec[i].val + index_vec[j].val;
      if (tmp == target) {
	res.push_back(min(index_vec[i].index, index_vec[j].index));
	res.push_back(max(index_vec[i].index, index_vec[j].index));
	return res;
      } else if (tmp < target) {
	i++;
      } else {
	j--;
      }
    }
    return res;
  }
};
