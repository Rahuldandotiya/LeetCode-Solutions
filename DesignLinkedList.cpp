class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    }*start=NULL;
    MyLinkedList() {
        
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(start==NULL) return -1;
        int count=0;
        ListNode *temp=start;
        while(temp){
            if(count==index) return temp->val;
            count++;
            temp=temp->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *temp=new ListNode(val);
        temp->next=start;
        start=temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *t=new ListNode(val);
        if(start==NULL){
            start=t;
            return;
        }
        ListNode *temp=start;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=t;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *t=new ListNode(val);
        ListNode *temp=start;
        ListNode *prev=NULL;
        int count=0;
        if(index==0){
            t->next=start;
            start=t;
            return;
        }
        while(temp!=NULL and count!=index){
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=t;
        t->next=temp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int count=0;
        ListNode *temp=start;
        if(index==0){
            start=temp->next;
            delete(temp);
            return;
        }
        while(temp!=NULL and count<index-1){
            count++;
            temp=temp->next;
        }
        if(temp==NULL or temp->next==NULL) return;
        ListNode *t=temp->next->next;
        delete(temp->next);
        temp->next=t;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
