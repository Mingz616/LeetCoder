/*
* 203. 移除链表元素
* 简单/相关标签/相关企业
* 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {  //如果头不为空，且头值等于target
        head = head->next;                          //头后一一个节点
    }

    struct ListNode *tmp = head;                //创建一个临时节点用来指向头
    while (tmp != NULL && tmp->next != NULL) {  //如果头不为空，且下一个节点也不为空,开始遍历
        if (tmp->next->val == val) {                //如果下一个节点的值，就是target
            tmp->next = tmp->next->next;                //下一个节点，指向下下一个节点
        } else {                                    
            tmp = tmp->next;                        //否则就继续遍历
        }
    }

    return head;
}

struct ListNode* createLinkedArray(int *array, int len, struct ListNode *head) {
    struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));           //创建临时结构体

    for (int i = 0; i < len; i++) {
        if (head == NULL) {                     //如果头为空
            tmp->val = array[i];                    //把列表中第一个值给到头
            tmp->next = head;                       //tmp和head都指向了头
            head = tmp;
        }
        else {                                  //如果头不为空
            struct ListNode *new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = array[i];                    //列表中的值给到新开辟的new
            new->next = NULL;           
            tmp->next = new;                        //tmp指向New
            tmp = new;                              //tmp指针移到尾
        }
    }

    return head;
}

void printLinkedArray(struct ListNode *head) {
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int array[] = {1,2,6,3,4,5,6};
    int target = 6;

    int len = sizeof(array) / sizeof(int);

    // 创建一个链表
    struct ListNode *head = NULL;

    //此处利用列表来生成链表
    head = createLinkedArray(array, len, head);
    //打印链表，确认生成是后插法
    printLinkedArray(head);
    //此处用来删除链表中的特定节点
    head = removeElements(head, target);
    //打印链表，检查
    printLinkedArray(head);

    return 0;
}