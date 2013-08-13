class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 1;
        if (n == 0) return res;
        int i = 0;
        
        while (i < n) {
            if (A[i] != i+1) {
                if (A[i] < n && A[i] > 0 && A[A[i]-1] != A[i]) {
                    swap(A[i], A[A[i]-1]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        
        for (i = 0; i < n; i++) {
            if (A[i] != i+1) return i+1;
        }
        
        return n+1;
       }
};