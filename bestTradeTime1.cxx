class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (prices.size() <= 1) return 0;
        
    int low = 0, profit = 0, max = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[low]) {
	max += prices[i] - prices[low];
      }
      low = i;
    }
        
    return max;
  }
};
