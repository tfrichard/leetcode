class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (num.size() == 0) return 0;
        
    unordered_map<int, int> lens_map;
        
    int res = 1;
        
    for (auto i : num) {
      if (lens_map.find(i) != lens_map.end()) {
	continue;
      }
            
      lens_map[i] = 1;
            
      if (lens_map.find(i-1) != lens_map.end()) {
	res = max(res, merge(lens_map, i - 1, i));
      }
            
      if (lens_map.find(i+1) != lens_map.end()) {
	res = max(res, merge(lens_map, i, i + 1));
      }
            
    }
        
    return res;
  }
    
  int merge(unordered_map<int, int> &lens_map, int left, int right) {
    int lower = left - lens_map[left] + 1;
    int upper = right + lens_map[right] - 1;
    int len = upper - lower + 1;
        
    lens_map[lower] = len;
    lens_map[upper] = len;
        
    return len;
  }
};
