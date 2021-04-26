class Solution {
public:
    vector<int> adj[100001];
    vector<int> low,in;
    vector<vector<int>> ans;
    void dfs(int node,int par,int timer)
    {
        low[node]=in[node]=++timer;
        
        for(auto child: adj[node])
        {
            if(child==par) //this cannot be a back edge so skip
                continue;
            
            if(!in[child]) //child not visited
            {
                dfs(child,node,timer); //forward edge
                
                if(low[child]>in[node])
                    ans.push_back({child,node});
                
                low[node]=min(low[child],low[node]);
            }
            else //child is visited
            {
                low[node]=min(low[child],low[node]);  //this mean a back edge
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low.resize(n,0);
        in.resize(n,0);
        for(auto v: connections)
        {
             adj[v[0]].push_back(v[1]);
             adj[v[1]].push_back(v[0]);
        }
        
        dfs(0,-1,0);
        
        return ans;
    }
};

//problem link 
//https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3719/
