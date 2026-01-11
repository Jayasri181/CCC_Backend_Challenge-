House Robber - LeetCode # 198 problem 

We are given an array nums representing the amount of money in each house. The goal is to find the maximum amount of money we can rob without robbing two adjacent houses.

My Approach
-------------------------------------------------------------------------
I solved this problem using dynamic programming with space optimization.

The main idea is to keep track of the maximum money we can rob up to the previous house and the house before that, instead of storing a full DP array.

1. p1 = maximum money we can rob up to the previous house

2. p2 = maximum money we can rob up to the house before the previous one

For each house, we have two choices:

 - Rob the current house → rob = p2 + nums[i]
 - Skip the current house → skip = p1

The best option for the current house:
 - curr = max(rob, skip)

Then we update:
 - p2 = p1
 - p1 = curr

After processing all houses, p1 contains the maximum money we can rob.

Base Cases:
If there is only one house, rob it
 - if(n == 1) return nums[0];

If there are no houses, maximum money = 0

Time Complexity
--------------------------------------------------------------------
We iterate through all n houses once

Each house requires O(1) computation

Time Complexity = O(n)

Space Complexity
-------------------------------------------------------------------
We only keep two variables (p1 and p2) to store previous results

No extra array is needed

Space Complexity = O(1)