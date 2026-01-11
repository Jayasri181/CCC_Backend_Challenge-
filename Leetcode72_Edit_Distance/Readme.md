Edit Distance - LeetCode #72 problem

We are given two strings, word1 and word2. The goal is to find the minimum number of operations needed to convert word1 into word2.

Allowed operations:
---------------------------------------------------
- Insert a character

- Delete a character

- Replace a character

My Approach
---------------------------------------------------
I solved this problem using dynamic programming.

The main idea is to build a table dp[i][j] where:

dp[i][j] = minimum number of operations to convert
           first i characters of word1
           into first j characters of word2


Transition rules:
---------------------------------------------------
If the characters match (word1[i-1] == word2[j-1]), no operation is needed:

dp[i][j] = dp[i-1][j-1]


If they don’t match, we consider all three possible operations and take the minimum:

dp[i][j] = 1 + min(
    dp[i-1][j],    // delete
    dp[i][j-1],    // insert
    dp[i-1][j-1]   // replace
)


Base Cases:

dp[0][j] = j → converting empty string to first j characters of word2

dp[i][0] = i → converting first i characters of word1 to empty string

This way, we fill the table row by row, and the last cell dp[m][n] gives the answer.

GREEDY APPROACH
A greedy approach might seem easy—just replace characters whenever they are different. But this doesn’t always give the minimum number of steps.

Example:

word1 = "abc"
word2 = "yabd"


Greedy way: replace 'a' → 'y', 'b' → 'a', 'c' → 'b', then insert 'd' → 4 operations

DP (best way): insert 'y' at the start, replace 'c' → 'd' → 2 operations

So, greedy fails because it only looks at the current characters, while dynamic programming considers all possibilities to find the smallest number of steps.


Time complexity 
-------------------------------------------------------------
Step-by-Step Time Complexity

Outer loop: runs i = 0..m → (m+1) iterations - O(m)

Inner loop: runs j = 0..n → (n+1) iterations - O(n)

TOTAL TIME O(m × n)

Space Complexity
--------------------------------------------------------------
We only store two rows of the DP table at a time, where m is the length of the smaller string.
Space Complexity: O(m)