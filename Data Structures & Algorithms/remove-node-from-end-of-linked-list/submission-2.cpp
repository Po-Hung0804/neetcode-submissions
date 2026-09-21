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
        /*
        if(!head->next && n==1){
            return nullptr;
        }
        int sz=1;
        ListNode* cur=head;
        while(cur){
            sz+=1;
            cur=cur->next;
        }
        int revise_node=sz-n;
        if(revise_node==1){
            return head->next;
        }
        int idx=1;
        cur=head;
        ListNode* prev=nullptr;
        while(idx!=revise_node){
            prev=cur;
            cur=cur->next;
            idx+=1;
        }
        prev->next=cur->next;
        return head;
        */
        // fast and slow two pointer
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};
