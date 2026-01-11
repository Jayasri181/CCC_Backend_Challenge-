**Predict the Winner – LeetCode 486**

We are given an integer array nums representing scores on the table. Two players take turns picking a number from either the start or the end of the array. Each player plays optimally.

The goal is to determine whether Player 1 can win or tie the game assuming both players make optimal choices.

**My Approach**
I solved this problem using Dynamic Programming (Score Difference Method).

Instead of tracking total scores separately, we track the maximum score difference the current player can achieve over the opponent.

**DP Definition**

Let dp[i][j] represent the maximum score difference the current player can obtain from the subarray nums[i…j].

A positive value means the current player is winning.

A negative value means the opponent is winning.

To optimize space, I used a 1D DP array, where dp[j] represents dp[i][j] for the current i.

**Transition Rules**

At each turn, the player has two choices:

1. Pick the left element (nums[i])

The opponent will then play optimally on [i+1…j]

Score difference = nums[i] - dp[j]

2. Pick the right element (nums[j])

The opponent will play optimally on [i…j-1]

Score difference = nums[j] - dp[j-1]

$$
dp[j] = max(
    nums[i] - dp[j],      // pick left
    nums[j] - dp[j - 1]   // pick right
)
$$

**Base Case
**
When i == j, there is only one number left:

dp[i] = nums[i]


This means the current player takes that number directly.

**Final Decision**

After filling the DP array, dp[n-1] represents the maximum score difference Player 1 can achieve over Player 2 for the entire array.

If dp[n-1] >= 0, Player 1 can win or tie

Otherwise, Player 1 loses

# Why Not Greedy?

A greedy approach (always picking the larger of the two ends) may seem correct, but it fails because it ignores future optimal responses by the opponent.

Dynamic programming works because it evaluates all possible choices and counter-choices, ensuring the optimal outcome.

**Time Complexity**

Two nested loops over the array

Time Complexity: O(n²)

**Space Complexity**

Uses a single DP array of size n

Space Complexity: O(n)