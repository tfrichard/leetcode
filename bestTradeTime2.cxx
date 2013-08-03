/*
naive version but the inituition is clear
*/

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (prices.size() <= 1) return 0;
        
    vector<int> lows;
    int low = 0, max = 0;
    lows.push_back(low);
        
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < prices[low]) {
	lows.push_back(i);
                
      }
      low = i;
    }
        
    int max1 = 0, max2 = 0;
    max = max1 + max2;
        
    for (int i = 0; i < lows.size(); i++) {
      max1 = maxProfit1(prices, 0, lows[i] + 1);
      max2 = maxProfit1(prices, lows[i], prices.size());
      if (max1 + max2 > max) {
	max = max1 + max2;
      }
    }
        
    return max;
  }
    
private:
  int maxProfit1(vector<int> &prices, int begin, int end) {
    int low = begin, profit = 0, max = 0;
    if (end - begin <=1) return 0;
    for (int i = begin + 1; i < end; i++) {
      if (prices[i] < prices[low]) {
	low = i;
      } else {
	if ((profit = prices[i] - prices[low]) > max) {
	  max = profit;
	}
      }
    }
    return max;
  }
};

