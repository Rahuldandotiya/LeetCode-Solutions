// The problem is solved with two approach
// 1.with memory O(N)
//2. without memory


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //unordered_set<ListNode*> m;
        int c1=0,c2=0;
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        while(headA){
            //m.insert(headA);
            headA=headA->next;
            c1++;
        }
        while(headB){
           /* if(m.find(headB)==m.end()){
                m.insert(headB);
            }
            else return headB;*/
            c2++;
            headB=headB->next;
        }
        if(c1>c2){
            for(int i=0;i<c1-c2;i++) curr1=curr1->next;
        }
        else for(int i=0;i<c2-c1;i++) curr2=curr2->next;
        while(curr1 and curr2){
            if(curr1==curr2) return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};
