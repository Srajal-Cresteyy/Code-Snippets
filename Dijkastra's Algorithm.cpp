class Solution
{
	public:
    vector <int> dijkstra(int Vertices, vector<vector<int>> adj[], int Source)
    {
        vector<int> distance(Vertices,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        distance[Source]=0;
        q.push({0,Source});
        while(!q.empty()){
            int node=q.top().second;
            int wieght=q.top().first;
            q.pop();
            
            for(auto &adjacent:adj[node]){
                int adj_node=adjacent[0];
                int new_wieght=wieght+adjacent[1];
                
                if(distance[adj_node]>new_wieght){
                    q.push({new_wieght,adj_node});
                    distance[adj_node]=min(distance[adj_node],new_wieght);
                }
            }
        }
        return distance;
    }
};
