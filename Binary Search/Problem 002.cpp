/*
Problem 002
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Input: 4
Output: 2

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/

/*
Intuition
Let's go back to the interview context. For x≥2, the square root is always smaller than x/2 and larger than 0 : 0 < a < x/2
Since a is an integer, the problem goes down to the iteration over the sorted set of integer numbers.
Here the binary search enters the scene.
*/

/*
Algorithm

    If x < 2, return x.

    Set the left boundary to 2, and the right boundary to x / 2.

    While left <= right:

        Take num = (left + right) / 2 as a guess. Compute num * num and compare it with x:

            If num * num > x, move the right boundary right = pivot -1

            Else, if num * num < x, move the left boundary left = pivot + 1

            Otherwise num * num == x, the integer square root is here, let's return it

    Return right
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x<2)     return x;
        int L=2;
        int R=x/2;
        int mid;
        while(L<=R)
        {
            mid=L+(R-L)/2;
            if(mid==x/mid)
                return mid;
            else if(mid<x/mid)
                L=mid+1;
            else
                R=mid-1;
        }
        return R;
    }
};
