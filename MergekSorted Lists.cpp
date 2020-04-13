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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        vector<int> v;
        for(int k=0;k<lists.size();k++){
            while(lists[k]!=NULL){
                v.push_back(lists[k]->val);
                lists[k]=lists[k]->next;
            }
        }
        if(v.size()==0) return head;
        sort(v.begin(),v.end());
        head=new ListNode(v[0]);
        ListNode* s=head;
        for(int i=1;i<v.size();i++){
            ListNode* t=new ListNode(v[i]);
            head->next=t;
            head=head->next;
        }
        return s;
    }
};
