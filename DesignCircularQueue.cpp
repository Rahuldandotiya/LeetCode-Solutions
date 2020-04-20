class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    struct node{
        int val;
        node *next;
    }*last=NULL;
    int count=0;
    int c;
    MyCircularQueue(int k) {
        c=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(count>=c) return false;
        if(last==NULL){
            node *temp=new node;
            temp->val=value;
            last=temp;
            last->next=last;
        }
        else{
            node *temp=new node;
            temp->val=value;
            temp->next=last->next;
            last->next=temp;
            last=temp;
        }
        count++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(last==NULL) return false;
        if(last->next==last){
            delete(last);
            last=NULL;
        }
        else{
            node *head=last->next;
            last->next=head->next;
            delete(head);
        }
        count--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(last==NULL) return -1;
        return last->next->val;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(last==NULL) return -1;
        return last->val;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(count==0) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(count==c) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
