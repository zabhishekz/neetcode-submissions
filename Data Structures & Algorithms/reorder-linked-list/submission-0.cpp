/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        // 2. Move to the tail of the first half & split the list
        temp = head;
        int steps = (len - 1) / 2;
        while (steps--) {
            temp = temp->next;
        }
        ListNode* curr = temp->next;
        temp->next = NULL;
    
        ListNode *prev = NULL;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* list1 = head;
        ListNode* list2 = prev;
        while(list2 != NULL){
            ListNode* tmp1 = list1->next;
            ListNode* tmp2 = list2->next;
            list1->next = list2;
            list2->next = tmp1;
            list1 = tmp1;
            list2 = tmp2;
        }
    }
};
