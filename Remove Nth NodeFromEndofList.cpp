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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* start=head;
        int i=1;
        while(i<n && start!=NULL){
            start=start->next;
            i++;
        }
        //cout<<start->val<<endl;
        while(start->next!=NULL){
            start=start->next;
            prev=temp;
            temp=temp->next;
        }
        //cout<<prev->val<<endl;
        //cout<<temp->val<<endl;
        if(prev==NULL) {
            head=head->next;
            return head;
        }
        if(temp->next==NULL){
            prev->next=NULL;
            return head;
        }
        prev->next=temp->next;
        return head;
    }
};
