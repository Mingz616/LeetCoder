/*
* 160. 相交链表
* 简单/相关标签/相关企业
* 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

* 题目数据 保证 整个链式结构中不存在环。
* 注意，函数返回结果后，链表必须 保持其原始结构 。

* 自定义评测：
*
* 评测系统 的输入如下（你设计的程序 不适用 此输入）：

* intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
* listA - 第一个链表
* listB - 第二个链表
* skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
* skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
* 评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 视作正确答案 。
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // 1. 找到每个链表的长度
    int lenA = 0;
    int lenB = 0;
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;

    while (curA != NULL) {
        lenA++;
        curA = curA->next;
    }
    while (curB != NULL) {
        lenB++;
        curB = curB->next;
    }
    // 2. 计算链表长度差并重新排序，让长的链表在前面
    int gap = 0;
    if (lenA < lenB) {
        gap = lenB - lenA;
        curA = headB;
        curB = headA;
    }
    else {
        gap = lenA - lenB;
        curA = headA;
        curB = headB;
    }
    // 3. 根据长度差，对齐两个链表
    while (gap--) {
        curA = curA->next;
    }
    // 4. 遍历两个链表的每个几点，试图找到并返回相同地址的节点
    while (curA != NULL) {
        if (curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    // 5. 如果没有，就返回NULL
    return NULL;
}

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
    int intersectVal = 8;
    int skipA = 2;
    int skipB = 3;

    int arrayA[] = {4,1,8,4,5};
    int arrayB[] = {5,6,1,8,4,5};
    
    int lenA = sizeof(arrayA) / sizeof(int);
    int lenB = sizeof(arrayB) / sizeof(int);

    struct ListNode* headA;
    headA = createLinkedList(arrayA, lenA);
    printLinkedList(headA);

    struct ListNode* headB;
    headB = createLinkedList(arrayB, lenB);
    printLinkedList(headB);

    struct ListNode* ret = getIntersectionNode(headA, headB);
    if (ret != NULL) {
        printf("%d\r\n", ret->val);
    }
    else {
        printf("NULL\r\n");
    }

    return 0;
}