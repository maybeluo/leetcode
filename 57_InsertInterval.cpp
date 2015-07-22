/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct compare {
    bool operator() (const Interval& a, const Interval& b) {
        return ( (a.start < b.start) || (a.start == b.start &&  a.end < b.end) );
    }  
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        compare cmp;
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> v;
        v.clear();
        int b = intervals[0].start, mx = intervals[0].end;
        for(int i = 1; i < n; i++) {
            if(intervals[i].start <= mx) {
                mx = max(mx, intervals[i].end);
            }
            else {
                Interval tp(b, mx);
                v.push_back(tp);
                b = intervals[i].start;
                mx = intervals[i].end;
            }
        }
        Interval tp(b, mx);
        v.push_back(tp);
        return v;
    }
};
