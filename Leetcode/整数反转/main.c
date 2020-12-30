#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {

    printf( "x=%d\n", x );
    int max_int = ~(unsigned int)(0) >> 1;
    int min_int = ~(unsigned int)(0) << 31;
    printf( "max_int=%d min_int=%d\n", max_int, min_int );

    int z_reverse = 0;

    int term = x;
    int current_digit = 1;
    while( term != 0 ) {
        z_reverse = z_reverse*10 + term%10; //��Ҫ�ڴ˴�������������
        term /= 10;
        if( z_reverse > max_int/10 && term != 0 ) {
            // ������ж�
            // ���������û��Ҫ��10��
            printf("�������\n");
            return 0;
        }
        else if( z_reverse < min_int/10 && term != 0 ){
            // ������ж�
            printf("�������\n");
            return 0;
        }

        current_digit++;
        printf( "z=%d term=%d\n", z_reverse, term );
    }

    printf("z=%d",z_reverse);
    return z_reverse;

}

int main()
{
    int z1 = 123;
    int z2 = -123;
    int z3 = 120;
    int z4 = 153423646;
    int z5 = 1534236469;
    int z6 = 0;

    reverse(z5);

    return 0;
}
