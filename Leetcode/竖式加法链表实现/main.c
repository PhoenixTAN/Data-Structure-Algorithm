#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1, *p2, *my_result, *pp1, *pp2, *p;
    p1 = l1;
    p2 = l2;
    int sum_of_two = 0;
    int carry = 0;
    pp1 = pp2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    my_result = pp1;

    while( p1 != NULL || p2 != NULL || carry == 1 ) {
        //* 两个链表长度可能不同
        //* 先算出当前位之和
        if( p1 == NULL && p2 != NULL ){
            sum_of_two = 0 + p2->val;
            printf( "p2 %d\n", p2->val );
            p2 = p2->next;

        }
        else if( p1 != NULL && p2 == NULL ) {
            sum_of_two = p1->val + 0;
            printf( "p1 %d\n", p1->val );
            p1 = p1->next;

        }
        else if( p1 != NULL && p2 != NULL ) {
            sum_of_two = p1->val + p2->val;
            printf( "%d %d\n", p1->val, p2->val );
            p1 = p1->next;
            p2 = p2->next;
        }

        //加入进位
        if( carry == 1 ) {
            sum_of_two++;
            carry = 0;
        }

        //* 判断是否会产生进位
        if( sum_of_two >= 10 ) {
            pp1->val = sum_of_two % 10;
            carry = 1;
        }
        else {
            pp1->val = sum_of_two;
        }
        sum_of_two = 0;
        printf( "pp1 %d\n", sum_of_two );

        if( p1 != NULL || p2 != NULL ){
            pp1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            pp2->next = pp1;
            pp2 = pp1;
        }
        else if( carry == 1 ){
            pp1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            pp2->next = pp1;
            pp2 = pp1;
            continue;
        }

    } // while结束

    pp1->next = NULL;

    p = my_result;
    while( p != NULL ) {
        printf( "%d ", p->val );
        p = p->next;
    }

    return my_result;

}


int main()
{
    struct ListNode *l1, *l2, *p1, *p2, *p;
    p1 = p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 2;
    l1 = p1;
    p2->next = p1;
    p2 = p1;

    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 4;
    p2->next = p1;
    p2 = p1;

    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 3;
    p2->next = p1;
    p2 = p1;

    p1->next = NULL;

    printf( "打印l1\n" );
    p = l1;
    while( p != NULL ) {
        printf( "%d ", p->val );
        p = p->next;
    }

    printf( "\n" );

    p1 = p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 5;
    l2 = p1;
    p2->next = p1;
    p2 = p1;
    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 6;
    p2->next = p1;
    p2 = p1;
    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 4;
    p2->next = p1;
    p2 = p1;
    p1->next = NULL;

    printf( "打印l2\n" );
    p = l2;
    while( p != NULL ) {
        printf( "%d ", p->val );
        p = p->next;
    }

    printf( "\n" );

    addTwoNumbers( l1, l2 );

    return 0;
}
