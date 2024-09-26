class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> hours = {8, 4, 2, 1};
        vector<int> minutes = {32, 16, 8, 4, 2, 1};
        vector<int> currentTime(10, 0);  // 0-3 for hours, 4-9 for minutes

        backtrack(result, num, 0, currentTime, hours, minutes);
        return result;
    }

    void backtrack(vector<string>& result, int num, int idx, vector<int>& currentTime,
                   const vector<int>& hours, const vector<int>& minutes) {
        if (num == 0) {
            int hour = 0, minute = 0;

            for (int i = 0; i < 4; ++i) hour += currentTime[i];
            for (int i = 0; i < 6; ++i) minute += currentTime[4 + i];

            if (hour < 12 && minute < 60) {
                string timeStr = to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
                result.push_back(timeStr);
            }
            return;
        }

        for (int i = idx; i < 10; ++i) {
            currentTime[i] = (i < 4 ? hours[i] : minutes[i - 4]);  // Select hour or minute bit
            backtrack(result, num - 1, i + 1, currentTime, hours, minutes);
            currentTime[i] = 0;  // Backtrack
        }
    }
};