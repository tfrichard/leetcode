class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (height.size() == 0) return 0;
        
    stack<int> indexs;
    int i = 0;
    int tp = 0;
    int left = 0;
    int area = 0;
    int max = 0;
        
    while (i < height.size()) {
      if (indexs.empty() || height[indexs.top()] < height[i]) {
	indexs.push(i);
	i++;
      } else {
	if (!indexs.empty()) {
	  if (height[indexs.top()] > height[i]) {
	    tp = indexs.top();
	    //indexs.pop();
	  } else {
	    tp = i;
	  }
	  indexs.pop();
	}
	left = indexs.empty() ? -1 : indexs.top();
	area = (i - left - 1) * height[tp];
	if (area > max) max = area;
      }
    }
        
    while (!indexs.empty()) {
      tp = indexs.top();
      indexs.pop();
      left = indexs.empty() ? -1 : indexs.top();
      area = (i - left - 1) * height[tp];
      if (area > max) max = area;
    }
        
    return max;
  }
};
