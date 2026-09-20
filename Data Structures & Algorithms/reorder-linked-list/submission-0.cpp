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
        // reverse the second half linklist
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(second){
            ListNode* tmp=second->next;
            second->next=prev;
            prev=second;
            second=tmp;
        }
        // merge the first half and second half with the order
        ListNode* cur=head;
        while(prev){
            ListNode* temp1=cur->next;
            ListNode* temp2=prev->next;
            cur->next=prev;
            prev->next=temp1;
            cur=temp1;
            prev=temp2;
        }
    }
};
