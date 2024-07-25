/*
2. 两数相加
    中等/相关标签/相关企业
|   给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
|   请你将两个数相加，并以相同形式返回一个表示和的链表。
|   你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a list structure with value and *next
struct ListNode{
    int val;
    struct ListNode *next;
};

// DEBUG CODE: print the list structure's value
void printList(struct ListNode *head) {
    while(head != NULL) {
        printf("%d", head->val);
        head = head->next;
    }
    putchar('\n');
}

// initialize the list reversely
static struct ListNode* nodeBuild(int *list, int len) {
    struct ListNode *head, *dummy, *p;
    head = NULL;

    while (len-- > 0) {
        p = (struct ListNode*)malloc(sizeof(*p));
        if (head == NULL) {
            p->val = *list++;
            p->next = head;
            head = p;
        } else {
            dummy = head;
            while(dummy->next != NULL) {
                dummy = dummy->next;
            }
            p->val = *list++;
            p->next = NULL;
            dummy->next = p;
        }
        
    }
    puts("Output List: ");
    printList(head);

    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *head = NULL;
    struct ListNode *dummy;

    while (l1 != NULL || l2 != NULL) {
        int sum = 0;

        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;       // if l1 or l2 is longer than each other
        carry = sum / 10;   // get carry

        struct ListNode* p = (struct ListNode*)malloc(sizeof(*p));
        if(head == NULL) {  
            p->val = sum % 10;
            p->next = head;
            head = p;
            dummy = head;
        } else {
            while (dummy->next != NULL) {
                dummy = dummy->next;
            }
            p->val = sum % 10;
            p->next = NULL;
            dummy->next = p;
        }
    }

    if(carry) {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(*p));
        while (dummy->next != NULL) {
            dummy = dummy->next;
        }
        p->val = carry;
        p->next = NULL;
        dummy->next = p;
    }

    return head;
}


int main()
{
    int list1[3] = {2, 4, 5};
    int len1 = sizeof(list1) / sizeof(int);

    int list2[3] = {5, 6, 4};
    int len2 = sizeof(list2) / sizeof(int);

    struct ListNode *l1 = nodeBuild(list1, len1);
    struct ListNode *l2 = nodeBuild(list2, len2);


    struct ListNode *sum = addTwoNumbers(l1, l2);
    printList(sum);

	return 0;
}