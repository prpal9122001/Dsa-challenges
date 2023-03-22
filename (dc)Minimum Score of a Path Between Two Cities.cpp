//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?orderBy=hot&page=17&languageTags=cpp

class Solution {
public:
    int ans=INT_MAX;
    unordered_set<int>st;
    int minScore(int n, vector<vector<int>>& arr) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<arr.size();i++)
        {
            int u=arr[i][0];
            int v=arr[i][1];
            int w=arr[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,adj);
        return ans;
    }
    void dfs(int src,vector<vector<pair<int,int>>>&adj)
    {
        if(st.find(src)!=st.end())
        {
            return;
        }
        st.insert(src);
        for(auto it=adj[src].begin();it!=adj[src].end();it++)
        {
            ans=min(ans,it->second);
            dfs(it->first,adj);
        }
    }
};
