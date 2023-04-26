class Solution
{
	public:
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> indegree(v),ans;
        for(int i=0;i<v;i++)
            for(auto adjacent:adj[i]){
                indegree[adjacent]++;
            }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0)
                q.push(i);
        
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjacent:adj[node]){
                if(indegree[adjacent])
                    indegree[adjacent]--;
                if(!indegree[adjacent])
                    q.push(adjacent);
            }
            ans.push_back(node);
        }
        return ans;
	}
};
