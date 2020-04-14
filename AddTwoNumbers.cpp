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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode* h2=l2;
        int res=0;
        while(h1!=NULL and h2!=NULL){
            res+=h1->val+h2->val;
            int n=res%10;
            res/=10;
            h1->val=n;
            h1=h1->next;
            h2=h2->next;
        }
        if(h1!=NULL){
            while(res!=0 and h1!=NULL){
                res+=h1->val;
                int n=res%10;
                res/=10;
                h1->val=n;
                h1=h1->next;
            }
        }
        if(h2!=NULL){
            ListNode* h4=h2;
            while(res!=0 and h2!=NULL){
                res+=h2->val;
                int n=res%10;
                res/=10;
                h2->val=n;
                h2=h2->next;
            }
            ListNode* h3=l1;
            while(h3->next!=NULL) h3=h3->next;
            h3->next=h4;
        }
        if(res!=0){
            ListNode* h3=l1;
            while(h3->next!=NULL) h3=h3->next;
            h3->next=new ListNode(res);
        }
        return l1;
    }
};
