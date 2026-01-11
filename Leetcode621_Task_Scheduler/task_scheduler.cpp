class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }
        int maxFreq = 0;
        for (auto it : freq) {
            maxFreq = max(maxFreq, it.second);
        }
        int countMax = 0;
        for (auto it : freq) {
            if (it.second == maxFreq) {
                countMax++;
            }
        }

        int minTime = (maxFreq - 1) * (n + 1) + countMax;

        return max(minTime, (int)tasks.size());
    }
};