class Solution {
public:
  string intToRoman(int num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function    
    /*        
Symbol    Value
I1
V5
X10
L50
C100
D500
M1,000
    */
    string res;
    if (num == 0) return res;
        
    while (num > 0) {
      if (num >= 1000) {
	res.push_back('M');
	num -= 1000;
      } else if (num >= 500) {
	if (num >= 900) {
	  res.push_back('C');
	  res.push_back('M');
	  num -= 900;
	} else {
	  res.push_back('D');
	  num -= 500;
	}
      } else if (num >= 100) {
	if (num >= 400) {
	  res.push_back('C');
	  res.push_back('D');
	  num -= 400;
	} else {
	  res.push_back('C');
	  num -= 100;
	}
      } else if (num >= 50) {
	if (num >= 90) {
	  res.push_back('X');
	  res.push_back('C');
	  num -= 90;
	} else {
	  res.push_back('L');
	  num -= 50;
	}
      } else if (num >= 10) {
	if (num >= 40) {
	  res.push_back('X');
	  res.push_back('L');
	  num -= 40;
	} else {
	  res.push_back('X');
	  num -= 10;
	}
      } else if (num >= 5) {
	if (num >= 9) {
	  res.push_back('I');
	  res.push_back('X');
	  num -= 9;
	} else {
	  res.push_back('V');
	  num -= 5;
	}
      } else if (num >= 1) {
	if (num >= 4) {
	  res.push_back('I');
	  res.push_back('V');
	  num -= 4;
	} else {
	  res.push_back('I');
	  num -= 1;
	}
      }
    }
    return res;
  }
};





