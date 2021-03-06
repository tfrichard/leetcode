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

//bfs solutino
class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (is_convertable(start, end)) return 2;
        
    if (dict.size() == 0) return 0;
        
    int length = 2;
    queue<string> cur_expand;
    unordered_set<string> visited;
    cur_expand.push(start);
    visited.insert(start);
    while (!cur_expand.empty()) {
      string cur = "";
      cur_expand.push("#");
      while (!cur_expand.empty() && (cur = cur_expand.front()) != "#") {
	cur_expand.pop();
	if (is_convertable(cur, end)) return length;
	for (string str : dict) {
	  if ((visited.find(str) == visited.end()) && is_convertable(cur, str)) {
	    cur_expand.push(str);
	    visited.insert(str);
	  }
	}
      }
      length += 1;
      cur_expand.pop();
      //cur_expand.push("#");
    }
        
    return 0;
  }
  
  inline bool is_convertable(string &src, string &dst) {
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
