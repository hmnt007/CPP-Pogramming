// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3770/

/**

Min Cost Climbing Stairs

Solution
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

**/

// Recursive Approach

class Solution {
public:
     int dp[1001];
    int solve(vector<int> &cost, int n , int step){
        if(step >=n) return 0;
        if(dp[step] > 0) return dp[step];
        return dp[step] = cost[step] + min(solve(cost, n, step+1),solve(cost, n, step+2));
     
       return min(dp[n-1], dp[n-2]); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int minCost1 = solve(cost, n, 0);
        int minCost2 = solve(cost, n, 1);
        return min(minCost1, minCost2);
    }
};

  
//   iterative approach
  
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
         for(int i = n-3; i>=0; i--){
             cost[i] = cost[i] + min(cost[i+1], cost[i+2]);
         }
        return min(cost[0], cost[1]);
    }
};