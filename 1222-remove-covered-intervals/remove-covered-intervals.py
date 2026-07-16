class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        count = 0
        prev_end = 0
        for l, r in intervals:
            if r > prev_end:
                count += 1
                prev_end = r
        return count