// https://www.interviewbit.com/problems/balanced-parantheses/

/**

Balanced Parantheses!
Asked in:  
Amazon
Google
Problem Description

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.



Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

 A = "(()())"
Input 2:

 A = "(()"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Given string is balanced so we return 1
Explanation 2:

 Given string is not balanced so we return 0

**/

// CODE

int Solution::solve(string A) {
    if(A == "") return 1;
    int openCount = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == '(') openCount++;
        else openCount--;
        if(openCount < 0) return 0;
    }
    if(openCount > 0) return 0;
    return 1;
}
