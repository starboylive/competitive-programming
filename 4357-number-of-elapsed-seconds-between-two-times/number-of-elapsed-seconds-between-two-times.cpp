class Solution {
public:
    int toSeconds(string t) {
        int nums[3] = {0};
        int index = 0;

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == ':') {
                index++;
            } else {
                nums[index] = nums[index] * 10 + (t[i] - '0');
            }
        }

        return nums[0] * 3600 + nums[1] * 60 + nums[2];
    }
    
    int secondsBetweenTimes(string startTime, string endTime) {
        return toSeconds(endTime) - toSeconds(startTime); 
    }
};
        