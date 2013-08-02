class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res;
        int len;
        if (a.size() > b.size()) {
            res = a;
            len = b.size();
        } else {
            res = b;
            len = a.size();
        }
        
        if (a.size() == 0 || b.size() == 0) return res;
        
        bool carry = false;
        int i;
        for (i = 0; i < len; i++) {
            if (a[i] == '1' && b[i] == '0' ||
            a[i] == '0' && b[i] == '1') {
                if (carry) {
                    res[i] = '0';
                } else {
                    res[i] = '1';
                }
            } else if (a[i] == '1' && b[i] == '1') {
                if (carry) {
                    res[i] = '1';
                } else {
                    res[i] = '0';
                    carry = true;
                }
            } else {
                if (carry) {
                    carry = false;
                    res[i] = '1';
                } else {
                    res[i] = '0';
                }
            }
        }
        
        while (i < res.size()) {
            if (carry) {
                if (res[i] == '1') {
                    res[i] = '0';
                } else {
                    res[i] = '1';
                    carry = false;
                }
            } else {
                break;
            }
            i++;
        }
        
        if (i >= res.size() && carry) {
            res.push_back('1');
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
