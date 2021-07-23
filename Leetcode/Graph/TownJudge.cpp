// https://leetcode.com/problems/find-the-town-judge/

/**
Find the Town Judge
Easy

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: n = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
**/

// CODE
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> hasTrust(n+1, false);
        
        //lets check if there exists one person who doesn't trust anyone
        for(int i=1; i<=trust.size(); i++) {
            hasTrust[trust[i-1][0]] = true;
        }
       
        int candidate_for_judge = -1;
        for(int i=1; i<=n; i++) {
            if(hasTrust[i] == false) {
                // he doesn't trust anyone so he is a candidate
                candidate_for_judge = i;
                break;
            }
        }
       
        if(candidate_for_judge < 1) return -1;
        
        // now lets checks for people who trust ith(candidate_for_judge) person
        hasTrust.assign(hasTrust.size(), false);
        hasTrust[candidate_for_judge] = true;
        for(int i=1; i<=trust.size(); i++){
            if( trust[i-1][1] == candidate_for_judge ) {
                hasTrust[trust[i-1][0]] = true;
            }
        }
        for(int i=1; i<=n; i++){
            if(hasTrust[i] == false) return -1;
        }
        return candidate_for_judge;   
    }
};