class LRUCache {
public:
    unordered_map<int,int> m;
    list<int> q;
    int k;
    LRUCache(int capacity) {
        k=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        q.remove(key);
        q.push_back(key);
        return m[key];
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            q.remove(key);
            m.erase(key);
        }
        if(m.size()==k){
            int n=q.front();
            q.pop_front();
            m.erase(n);
        }
        m[key]=value;
        q.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
