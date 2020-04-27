class Solution {
public:
    bool dfs(int u,vector<vector<int>> &adj,vector<int> &visited){
        if(visited[u]==1) return false;
        visited[u]=1;
        for(auto a:adj[u]){
            if(!dfs(a,adj,visited)) return false;
        }
        visited[u]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        if(numCourses==0 or prerequisites.size()==0) return true;
        for(auto i:prerequisites) adj[i[0]].push_back(i[1]);
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(!dfs(i,adj,visited)) return false;
            }
        }
        return true;
    }
};
