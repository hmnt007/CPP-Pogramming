// https://www.interviewbit.com/problems/grid-unique-paths/

/**

Grid Unique Paths

Asked in:  
Google
Amazon
Microsoft
Adobe
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
**/

// CODE

int Solution::uniquePaths(int A, int B) {
    int n = (A-1)+(B-1);
    if(A < B) swap (A, B);
    int r = A-1;
    long int paths = 1;
    for(int i=1; i <= r; i++) {
        paths = paths * (n-r+i)/i;
    }
    return int(paths);
}

