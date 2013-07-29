OBclass Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (num.size() < 3) return -1;
        
    sort(num.begin(), num.end());
    int min = 9999999;
    int res = num[0] + num[1] + num[2];
    for (int i = 0; i < num.size() - 2; i++) {
      int tmpTarget = target - num[i];
      int tmpTwoSum = twoSum(num, i+1, tmpTarget);
      if (abs(tmpTarget - tmpTwoSum) < min) {
	min = abs(tmpTarget - tmpTwoSum);
	res = num[i] + tmpTwoSum;
      }
    }
        
    return res;
  }
    
private:
  int twoSum(vector<int> &num, int begin, int target) {
    int end = num.size() - 1;
    int min = 9999999;
    int res = num[begin] + num[end];
    while (begin < end) {
      int tmpSum = num[begin] + num[end];
      if (tmpSum > target) {
	end -= 1;
	if (min > tmpSum - target) {
	  min = tmpSum - target;
	  res = tmpSum;
	}
      } else if (tmpSum < target) {
	begin += 1;
	if (min > target - tmpSum) {
	  min = target - tmpSum;
	  res = tmpSum;
	}
      } else {
	return tmpSum;
      }
    }
    return res;
  }
};
