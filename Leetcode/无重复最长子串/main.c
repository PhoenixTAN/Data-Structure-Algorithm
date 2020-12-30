#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int length = 1;
    int max_length = 1;
    //作为滑动窗口的左右边界
    int left = 0;
    int right = 0;

    //构造哈希表
    int myHash[256];
    int i = 0;
    int j = 0;
    // 初始化Hash Table
    for( i = 0; i <= 256 - 1; i++ ) {
        myHash[i] = -1;
    }

    //空字符串
    if( s[0] == '\0' ) {
        max_length = 0;
        return max_length;
    }

    printf( "left = %d right = %d ,", left, right );

    for( i = 0; s[i] != '\0'; i++ ) {
        myHash[s[i]] = i;

        printf( "i = %d ,", i );
        printf( "myHash[%c] = %d\n", s[i], i );
        right++;
        printf( "left = %d right = %d ,", left, right );
        if( s[right] != '\0' ) {

            if( myHash[s[right]] == -1 ){
                //暂时没有出现重复字符
                printf( "暂时没有出现重复字符!\n" );
                length = right - left + 1;
                if( length > max_length ) {
                    max_length = length;
                }
                printf( "length = %d max_length = %d\n", length, max_length );
            }
            else{
                //出现重复字符
                printf( "出现重复字符!\n" );

                //这里要注意重新初始化哈希表
                //滑动窗口左边界到上一个重复字符的字母都要归0
                int term = myHash[s[right]];
                for( j = left; j <= myHash[s[right]]; j++ ) {
                    if( myHash[s[j]] != -1 ) {
                        myHash[s[j]] = -1;
                        printf( "初始化%c ", s[j] );
                    }
                }

                //重新定义滑动窗口长度
                //从重复字符的下一个字符开始计算
                left = term + 1;
                length = right - left + 1;
                if( length > max_length ) {
                    max_length = length;
                }

                printf( "left = %d right = %d\n", left, right );
                printf( "length = %d max_length = %d\n", length, max_length );
            }
        }
        printf( "\n" );
    }

    printf( "%d", max_length );
    return max_length;
}

int main()
{
    //char s1[7] = { 'p', 'w', 'w', 'k', 'e', 'w', '\0' };
    //char s1[9] = { 'a', 'b', 'c', 'a', 'b', 'c', 'b', 'b', '\0' };
    //char s1[9] = { 't', 'm', 'm', 'z', 'u', 'x', 't', '\0' };
    char s1[] = { 'k','a','w','m','u','c','q','d','l','u','b','p','m','b','q','y','f','h','c','w','m','h','f','o','o','g','x','z','x','g','u','h','i','s','w','d','w','m','i','i','g','j','z','u', '\0'};
    lengthOfLongestSubstring( s1 );

    return 0;
}

