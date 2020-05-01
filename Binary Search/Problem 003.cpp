/*
Problem 003
Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Input: n = 10, pick = 6
Output: 6
*/

/*
Algorithm

We can apply Binary Search to find the given number. We start with the mid number. We pass that number to the guess function.
If it returns a -1, it implies that the guessed number is larger than the required one.
Thus, we use Binary Search for numbers lower than itself. Similarly, if it returns a 1,
we use Binary Search for numbers higher than itself.
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int L=1;
        int R=n;
        int mid;
        while(L<=R)
        {
            mid=L+(R-L)/2;
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)<0)
                R=mid-1;
            else
                L=mid+1;
        }
        return -1;
    }
};
