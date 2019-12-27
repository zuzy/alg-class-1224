#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *tmp, dummy;
    dummy.next = NULL;
    tmp = &dummy;

    while(l1 || l2) {
        if(l1 && l2) {
            if(l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
        } else{
            if(l1) {
                tmp->next = l1;
            } else {
                tmp->next = l2;
            }
            break;
        }
        tmp = tmp->next;
    }
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *mid, *tail;
    mid = head;
    tail = head->next;

    while(tail) {
        tail = tail->next;
        if(tail == NULL) break;
        mid = mid->next;
        tail = tail->next;
    }

    struct ListNode *left = head;
    struct ListNode *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);
    
    return mergeTwoLists(left, right);
}

static void _create_random_list(struct ListNode *dummy, unsigned int size, int range)
{
    int i;
    struct ListNode *tmp, *ptr;
    printf("Create List:\n");
    for(ptr = dummy, i = 0; i < size;++i, ptr = ptr->next) {
        tmp = malloc(sizeof(struct ListNode));
        tmp->val = 1 + rand() / ((RAND_MAX + 1u) / range);
        ptr->next = tmp;
        printf("(%d: %d)\t", i, tmp->val);
    }
    printf("\n");
    tmp->next = NULL;
}

static void _clean_list(struct ListNode *head)
{
    struct ListNode *tmp;
    while(head) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("Usage: %s <list_size>\n", argv[0]);
        exit(1);
    }
    srand(time(NULL));
    struct ListNode dummy1 = {0}, dummy2 = {0}, *p1, *p2;
    int i = 0;
    unsigned int list1_size = atoi(argv[1]);
    // unsigned int list2_size = atoi(argv[2]);
    _create_random_list(&dummy1, list1_size, list1_size + 1);
    // _create_random_list(&dummy2, list2_size);

    // struct ListNode *ret = mergeTwoLists(dummy1.next, dummy2.next);

    struct ListNode *ret = sortList(dummy1.next);

    printf("Result:\n");
    i = 0;
    
    struct ListNode *tmp;
    while(ret) {
        tmp = ret;
        printf("(%d: %d)\t", i++, ret->val);
        ret = ret->next;
        free(tmp);
        tmp = NULL;
    }
    printf("\n");
    return 0;
}