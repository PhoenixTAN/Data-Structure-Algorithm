#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {

    int max_length = 0;
    int length = 0;
    static char palindrom[1002] = "";
    int p1 = 0;
    int p2 = 0;

    if( s[0] == '\0'  || s == NULL ) {
        return palindrom;
    }
    if( s[1] == '\0' ) {
        return palindrom;
    }

    int i = 0;

    for( i = 1; s[i+1] != '\0'; i++ ) {
        int j = 0;
        int k = 0;
        if( s[i] == s[i+1] ) {
            //situation1
            j = i;
            k = i + 1;
            length = 2;
            if( length > max_length ) {
                max_length = length;
                p1 = j;
                p2 = k;
            }
        }
        else if( s[i-1] == s[i+1] ) {
            //situation2
            j = i - 1;
            k = i + 1;
            length = 2;
            if( length > max_length ) {
                max_length = length;
                p1 = j;
                p2 = k;
            }

        }

        j--;
        k++;
        while( j >= 0 && s[k] != '\0' ) {
            if( s[j] == s[k] ) {
                length = length + 2;
                if( length > max_length ) {
                    max_length = length;
                    p1 = j;
                    p2 = k;
                }
                j--;
                k++;

            }
            else {
                break;
            }

        }
    }

    int m = 0;
    //printf( "p1=%d p2=%d\n", p1, p2);
    for( i = p1; i <= p2; i++, m++ ) {

        palindrom[m] = s[i];
        //printf( "m=%d %c\n", m, palindrom[m] );

    }
    //palindrom[m+1] = '\0';

    printf( "%s", palindrom );
    return palindrom;
}

int main()
{
    char s1[6] = {'b', 'a', 'b', 'a', 'd', '\0' };
    char s2[5] = {'c', 'b', 'b', 'd', '\0' };
    char s3[5] = {'b', 'b', 'b', 'b', '\0' };
    char s4[2] = {'b', '\0' };
    char s5[3] = {'b', 'b', '\0' };
    char s6[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char s7[] = "cbbd";
    longestPalindrome(s4);

    return 0;
}
