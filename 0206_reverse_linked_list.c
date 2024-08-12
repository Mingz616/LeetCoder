/*
* 206. 反转链表
* 简单/相关标签/相关企业
* 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct LIstNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 第一种反转的方法：我自己的思路
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;

    while (head != NULL) {                                                          //只要当前节点不为空
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = head->val;
        tmp->next = prev;
        prev = tmp;
        head = head->next;
    }

    return prev;
}

struct ListNode* reverseList2(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *tmp = head;

    while (tmp != NULL) {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    return prev;
}

/* 递归法 */
struct ListNode* reverse(struct ListNode* prev, struct ListNode* current) {
    if (current == NULL) return prev;
    struct ListNode* tmp = current->next;
    current->next = prev;
    prev = current;
    current = tmp;

    return reverse(prev, current);
}

struct ListNode* reverseList3(struct ListNode* head) {
    return reverse(NULL, head);
}
/* 递归法 */


struct ListNode* createLinkedList(int *ptr, int len) {
    if (len == 0) {
        struct ListNode *head = NULL;  
        return head;
    }

    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = ptr[0];
    head->next = NULL;

    struct ListNode *node = head;
    for (int i = 1; i < len; i++) {
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = ptr[i];
        node->next = tmp;
        node = tmp;
    }
    node->next = NULL;

    return head;
}

void printLinkedList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\nDone\n");
}

int main() {
    //[1,2,3,4,5]
    //[1,2]
    //[]
    int myArray[] = {1,2,3,4,5};
    int len = sizeof(myArray) / sizeof(int);
    printf("%d\r\n", len);
    //创建一个新链表的头指针
    struct ListNode *head;
    //根据数列内容来创建链表
    head = createLinkedList(myArray, len);
    printLinkedList(head);

    head = reverseList3(head);
    printLinkedList(head);

    return 0;
}