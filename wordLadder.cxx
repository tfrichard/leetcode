class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth = dict.size();
        int size = start.size();
        int i;
        map<string, bool> visited;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            visited[*it] = false;
        }
        visited[start] = true;
        
        if (isSim(start, end, size)) return 2;
        
        for (i = 1; i < depth; i++) {
            if (dfs(start, end, dict, 0, i, size, visited)) {
                return i + 2;
            }
        }
        return 0;
    }
    
    bool dfs(string start, string end, unordered_set<string> &dict, int depth, int &limit, int &size, map<string, bool> &visited) {
        if (depth >= limit) return false;
        
        bool res = false;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            if (!visited[*it] && isSim(start, *it, size)) {
                if (isSim(*it, end, size)) return true;
                else {
                    visited[*it] = true;
                    res = dfs(*it, end, dict, depth + 1, limit, size, visited);
                    visited[*it] = false;
                }
            }
        }
        return res;
    }
    
    bool isSim(const string &str1, const string &str2, int size) {
        int numDiff = 0;
        for (int i = 0; i < size; i++) {
            if (str1[i] != str2[i]) numDiff++;
        }
        if (numDiff == 1) return true;
        else return false;
    }
};
