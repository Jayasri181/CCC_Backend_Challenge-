class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
                                    // make word2 smaller for space to be minimum
        if (m > n)
            return minDistance(word2, word1);
        vector<int> prev(m + 1), curr(m + 1);
                                      // converting empty word1 to word2
        for (int j = 0; j <= m; j++)
            prev[j] = j;
        for (int i = 1; i <= n; i++) {
            curr[0] = i;              // delete all characters from word1
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({
                        prev[j],       // delete character
                        curr[j - 1],   // insert
                        prev[j - 1]    // replace
                    });
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};