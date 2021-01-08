# Leetcode 866 --- Prime Palindrome

Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:
```
Input: 6
Output: 7
```
Example 2:
```
Input: 8
Output: 11
```
Example 3:
```
Input: 13
Output: 101
```

Note:
```
1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.
```

## 回文数生成器
```java
class Solution {
    public int primePalindrome(int N) {
        
        // 1 <= N <= 10^8
        // The answer is less than 2*10^8
        int maxLength = 5;
        for (int L = 1; L <= maxLength; L++) {
            //Check for odd-length palindromes
            for (int root = (int)Math.pow(10, L - 1); root < (int)Math.pow(10, L); ++root) {
                int x = findNextOddlengthPalindrome(root);
                if (x >= N && isPrime(x))
                    return x;
                    //If we didn't check for even-length palindromes:
                    //return N <= 11 ? min(x, 11) : x
            }

            //Check for even-length palindromes
            for (int root = (int)Math.pow(10, L - 1); root < (int)Math.pow(10, L); ++root) {
                int x = findNextEvenlengthPalindrome(root);
                if (x >= N && isPrime(x))
                    return x;
            }
        }
        return 0;
    }
    
    private int findNextOddlengthPalindrome(int root) {
        int ans = root;
        root /= 10;
        while( root > 0 ) {
            ans *= 10;
            ans += root % 10;
            root /= 10;
        }
        return ans;
    }
    
    private int findNextEvenlengthPalindrome(int root) {
        int ans = root;
        while( root > 0 ) {
            ans *= 10;
            ans += root % 10;
            root /= 10;
        }
        return ans;
    }
    
    private boolean isPrime(int x) {
        if( x < 2 ) {
            return false;
        }
        int upper = (int)(Math.sqrt(x));
        for( int i = 2; i <= upper; i++ ) {
            if( x % i == 0 ) {
                return false;
            }
        }
        
        return true;
    }
    
}
```
