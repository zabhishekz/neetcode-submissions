/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compareIntervals(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), compareIntervals);

        Interval prevWindow = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < prevWindow.end){
                return false;
            }
            else{
                prevWindow = intervals[i];
            }
        }
        return true;
    }
};
