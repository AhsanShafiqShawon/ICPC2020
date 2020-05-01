/*
Problem 005
First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version
of your product fails the quality check. Since each version is developed based on the previous version, all the versions
after a bad version are also bad. Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
which causes all the following ones to be bad. You are given an API bool isBadVersion(version) which will return
whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version.
*/

/*
It is not difficult to see that this could be solved using a classic algorithm - Binary search. Let us see how the search space
could be halved each time below.

Scenario #1: isBadVersion(mid) => false

 1 2 3 4 5 6 7 8 9
 G G G G G G B B B       G = Good, B = Bad
 |       |       |
left    mid    right

Let us look at the first scenario above where isBadVersion(mid)⇒false. We know that all versions preceding and including mid are
all good. So we set left=mid+1 to indicate that the new search space is the interval [mid+1,right] (inclusive).

Scenario #2: isBadVersion(mid) => true

 1 2 3 4 5 6 7 8 9
 G G G B B B B B B       G = Good, B = Bad
 |       |       |
left    mid    right


*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L=1;
        int R=n;
        int mid;
        while(L<R)
        {
            mid=L+(R-L)/2;
            if(isBadVersion(mid)==true)
                R=mid;
            else
                L=mid+1;
        }
        return L;
    }
};
