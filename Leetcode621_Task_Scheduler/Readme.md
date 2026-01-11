**Task Scheduler – LeetCode #621**

We are given a list of tasks represented by capital letters. Each task takes 1 unit of time to execute.
The same task must have a cooldown period of n units before it can be executed again.

The goal is to find the minimum number of time units required to complete all tasks.

**My Approach**

I solved this problem using a Greedy approach combined with Frequency Counting.

The key idea is that the task with the highest frequency determines the minimum time required, because repeated tasks must be spaced apart due to the cooldown constraint.

**Frequency Counting**

First, we count how many times each task appears.

Let maxFreq be the maximum frequency of any task.

Let countMax be the number of tasks that appear exactly maxFreq times.

These values help determine how many idle slots are needed.

**Scheduling Insight**

If a task appears maxFreq times, we can think of arranging it like this:

A _ _ A _ _ A ...

There are (maxFreq - 1) gaps between these tasks, and each gap must be at least n units apart.

Each block has a size of (n + 1):

1 slot for the task

n slots for cooldown (other tasks or idle)

So, the minimum time needed becomes:
   ```cpp
   (minimum time) = (maxFreq - 1) × (n + 1) + countMax
   ```

countMax is added because multiple tasks can share the last block if they have the same maximum frequency.

# Final Answer

Sometimes, there are enough different tasks to fill all idle slots, so no extra idle time is needed.

Therefore, the final answer is:
  ```c++
   max(minTime, total number of tasks)
  ```

This ensures we return the correct time whether idle slots are required or not.

**Why Greedy Works Here**

A greedy approach works because:

The most frequent task always creates the tightest constraint

Placing high-frequency tasks first minimizes idle time

Lower-frequency tasks naturally fill the gaps

Trying to simulate each step would be inefficient, but this formula captures the optimal schedule directly.

**Time Complexity**

Counting frequencies: O(n)

Iterating over at most 26 tasks

Total Time Complexity: O(n)

**Space Complexity**

Frequency map stores at most 26 tasks

Space Complexity: O(1)