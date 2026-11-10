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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        int idx = len-n;
        if (idx == 0) {
            return head->next;
        }

        temp = head;
        while(temp != NULL){
            if(idx == 1){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
            idx--;
        }
        return head;
    }
};
