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
struct ListNode *detectCycle(struct ListNode *head) {
    // 1. 定义双指针，一个快指针，一次走两步；一个慢指针，一次走一步
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    // 2. 指针开始移动，直到两个指针相遇
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          //step 1
        fast = fast->next->next;    //step 2

        // 3. 在相遇后，让头节点和相遇节点开始遍历
        if (slow == fast) {
            struct ListNode* dummyhead = head;
            struct ListNode* entrance = fast; 

            // 4. 如果遍历到相同的节点，此节点就是环路的入口
            while (dummyhead != entrance) {
                dummyhead = dummyhead->next;
                entrance = entrance->next;
            }
            return dummyhead;
        }
    }
    // 5. 否则，就返回NULL
    return NULL;
}

struct ListNode* createCycledLinkedList(int *ptr, int len, int cycle) {
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

    struct ListNode* dummyEntrance = head;
    while (--cycle) {
        dummyEntrance = dummyEntrance->next;
    }
    node->next = dummyEntrance;

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
    int array[] = {3,2,0,-4};
    int cycle = 2;
    
    int len = sizeof(array) / sizeof(int);

    struct ListNode* head;
    head = createCycledLinkedList(array, len, cycle);
    // printLinkedList(head);       //因为是循环链表，所以不能打印，会进入死循环

    struct ListNode* ret = detectCycle(head);
    if (ret != NULL) {
        printf("%d\r\n", ret->val);
    }
    else {
        printf("No Cycle\r\n");
    }

    return 0;
}