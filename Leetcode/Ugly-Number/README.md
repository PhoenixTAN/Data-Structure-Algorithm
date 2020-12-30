# Ugly-Number

## Leetcode 263. Ugly Number
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

1 is typically treated as an ugly number.

```java
class Solution {
    public boolean isUgly(int num) {
        if ( num <= 0 ) {
            return false;
        }
        while ( num % 2 == 0 ) num /= 2;  // 不断除以2，直到不能被2整除
        while ( num % 3 == 0 ) num /= 3;  // 不断除以3，直到不能被3整除
        while ( num % 5 == 0 ) num /= 5;  // 不断除以5，直到不能被5整除
        
        // 看看最后剩下的是不是1
        if ( num != 1 ) {
            return false;
        }
        return true;
    }
}
```

## Leetcode 264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

### 方法一： 用上一题的方法遍历
但是会超时，因为有很多数都不是丑数。

### 方法二： 优先队列+记忆化
使用优先队列，一个一个丑数往里面加，一个一个往外面出列，出列一个数，往后加3个丑数。
```java
class Solution {
    public int nthUglyNumber(int n) {
        // priority queue
        int index = 0;  // index th ugly
        long targetUglyNum = 0;
        PriorityQueue<Long> queue = new PriorityQueue<Long>();
        Set<Long> visited = new HashSet<Long>();
        // initialize queue
        queue.add(1L);
        visited.add(1L);
        while ( index < n ) {
            targetUglyNum = queue.poll();    // 弹出队头元素
            // System.out.println("index="+index+" "+"peek="+targetUglyNum);
            // 下三个丑数入栈
            long num2 = targetUglyNum * 2;
            long num3 = targetUglyNum * 3;
            long num5 = targetUglyNum * 5;
            if ( !visited.contains(num2) ) {
                queue.add(num2);
                visited.add(num2);
            }
            if ( !visited.contains(num3) ) {
                queue.add(num3);
                visited.add(num3);
            }
            if ( !visited.contains(num5) ) {
                queue.add(num5);
                visited.add(num5);
            }
            index++;
        }

        return (int)targetUglyNum;
    }
}
```

### 方法三： 动态规划
下一个丑数的状态跟上一个有关，类似找质数填数的方法。
```java
class Solution {
    static int[] ugly = new int[1690];
    public int nthUglyNumber(int n) {
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        ugly[0] = 1;
        for ( int i = 1; i < n; i++ ) {
            int num2Next = ugly[p2]*2;
            int num3Next = ugly[p3]*3;
            int num5Next = ugly[p5]*5;

            ugly[i] = Math.min(Math.min(num2Next, num3Next), num5Next);
            
            if ( ugly[i] == num2Next ) p2++;
            if ( ugly[i] == num3Next ) p3++;
            if ( ugly[i] == num5Next ) p5++;
        }
        return ugly[n-1];
    }
}
```
