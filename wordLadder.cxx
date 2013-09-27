class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    unordered_map<string, bool> visited;
    for (string str : dict) visited[str] = false;
        
    int cutoff = 2;
    if (is_convertable(start, end)) return cutoff;
        
    while (cutoff <= dict.size() + 2) {
      cutoff += 1;
      if (dfs(start, end, visited, dict, 1, cutoff)) return cutoff;
            
    }
        
    return 0;
  }
    
  bool dfs(string &start, string &end, unordered_map<string, bool> &visited, 
	   unordered_set<string> &dict, int depth, const int &cutoff) {
    if (depth >= cutoff) return false;
        
    if (is_convertable(start, end)) return true;
        
    for (string str : dict) {
      if (visited[str] == true) continue;
            
      if (is_convertable(start, str)) {
	visited[str] = true;
	if (dfs(str, end, visited, dict, depth + 1, cutoff)) {
	  return true;
	}
	visited[str] = false;
      }
    }
        
    return false;
  }
    
  bool is_convertable(string &src, string &dst) {
    if (src == dst) return true;
        
    int cnt = 0;
    for (int i = 0; i < src.size(); i++) {
            
      if (src[i] != dst[i]) {
	cnt += 1;
	if (cnt > 1) return false;
      }
    }
        
    return cnt == 1;
  }
};
