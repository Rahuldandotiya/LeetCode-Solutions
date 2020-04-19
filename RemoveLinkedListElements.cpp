/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        //while(head->val==val) head=head->next;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL and temp->next!=NULL){
            if(temp->next->val==val){
                ListNode *t=temp->next->next;
                delete(temp->next);
                temp->next=t;
            }
            else temp=temp->next;
        }
        if(temp!=NULL and temp->val==val and temp->next==NULL) return NULL;
        if(head->val==val) head=head->next;
        return head;
    }
};
