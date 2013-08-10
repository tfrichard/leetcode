class Solution {
public:
  int maxArea(vector<int> &height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int max = 0;
    if (height.size() == 0) {
      return max;
    }
        
    int i = 0;
    int j = height.size() - 1;
    int res = max;
    while (i < j) {
      int h = (height[i] >= height[j]) ? height[j] : height[i];
      res = h * (j - i);
      if (res > max) max = res;
            
      if (height[i] <= height[j]) {
	i++;
	while (height[i] < h && i < j) i++;
      } else {
	j--;
	while (height[j] < h && i < j) j--;
      }
    }
        
    return max;
  }
};
