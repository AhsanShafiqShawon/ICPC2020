///The problem is to calculate the number of ways to choose two distinct integers from 1 to n with sum equals k.

/*If k<=n then the answer is floor(k/2) because this is the number of ways to choose two distinct integers
from 1 to k-1 with the sum equals k. Otherwise let mn=n-k will be the minimum possible term in the correct pair of integers. Also
let mx=n will be the maximum possible term in the correct pair of integers. Then the answer is max(0, floor((mx-mn+1)/2)) because this
is the number of ways to choose two distinct integers from mn to mx with the sum equals k.*/
