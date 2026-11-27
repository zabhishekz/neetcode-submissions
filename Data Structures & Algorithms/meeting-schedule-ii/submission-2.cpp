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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compareIntervals);

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const auto& interval : intervals) {
            if(!minHeap.empty() and interval.start >= minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
