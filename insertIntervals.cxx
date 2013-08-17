/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<Interval> res;
    if (intervals.size() == 0) {
      res.push_back(newInterval);
      return res;
    }
        
    int i = 0;
    int size = intervals.size();
        
    while (i < size && intervals[i].start <= newInterval.start) {
      if (intervals[i].end < newInterval.start)
	res.push_back(intervals[i]);
      else {
	newInterval.start = intervals[i].start;
      }
            
      if (intervals[i].end > newInterval.end) {
	newInterval.end = intervals[i].end;
      }
            
      i++;
    }
        
    if (i == size) {
      if (intervals[i-1].end < newInterval.start) {
	res.push_back(newInterval);
	return res;
      }
      Interval intev;
      intev.start = intervals[i-1].start;
      intev.end = max(intervals[i-1].end, newInterval.end);
      res.push_back(intev);
      return res;
    }
        
    int newStart = newInterval.start;
        
    if (i < size && intervals[i].start > newInterval.end) {
      res.push_back(newInterval);
      while (i < size) {
	res.push_back(intervals[i]);
	i++;
      }
      return res;
    } else {
      //merge will happen
      while (i < size && intervals[i].end < newInterval.end) {
	i++;
      }
            
      if (i == size) {
	int newEnd = newInterval.end;
	Interval intev;
	intev.start = newStart;
	intev.end = newEnd;
	res.push_back(intev);
	return res;
      }
            
      if (intervals[i].start > newInterval.end) {
	res.push_back(newInterval);
      } else {
	int newEnd = intervals[i].end;
	Interval intev;
	intev.start = newStart;
	intev.end = newEnd;
	res.push_back(intev);
	i++;
      }
            
      while (i < size) {
	res.push_back(intervals[i]);
	i++;
      }
    }
        
    return res;
  }
};



