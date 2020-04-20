class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(!q.empty()){
            int time=q.front();
            while(!q.empty() and t-time>3000){
                q.pop();
                time=q.front();
            }
            q.push(t);
        }
        else q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
