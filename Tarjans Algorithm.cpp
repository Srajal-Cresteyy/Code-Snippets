class TarjansAlgo {
public:
    vector<int> time,low;
    vector<vector<int>> ans;
    void dfs(int src,int parent,int steps,vector<int> adj[],vector<int> &visited){
        visited[src]=1;
        time[src]=steps;
        low[src]=steps;
        for(auto adjacent:adj[src]){
            if(visited[adjacent]==0){
                steps++;
                dfs(adjacent,src,steps,adj,visited);
            }
            if(adjacent!=parent)
                low[src]=min(low[src],low[adjacent]);
            if(time[src]<low[adjacent])
                ans.push_back({src,adjacent});
        }
    }
    vector<vector<int>> bridges(int n, vector<vector<int>>& connections) {
        vector<int> adj[n],visited(n);
        low.resize(n,INT_MAX);
        time.resize(n,INT_MAX);
        for(auto connect:connections){
            int u=connect[0];
            int v=connect[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int node=0;node<n;node++){
            if(!visited[node])
                dfs(node,-1,1,adj,visited);
        }

        return ans;
    }
};
