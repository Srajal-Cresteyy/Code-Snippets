class DisjointSet{
    vector<int> rank,parent,size;
  public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int p=0;p<n+1;p++)
            parent[p]=p;
    }

    int FindUParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=FindUParent(parent[node]);
    }

    void UnionRank(int u,int v){
        int upu=FindUParent(u);
        int upv=FindUParent(v);
        if(upu==upv) return;
        if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }
        else {
            parent[upv]=upu;
            rank[upu]++;
        }
    }

    void UnionSize(int u,int v){
        int upu=FindUParent(u);
        int upv=FindUParent(v);
        if(upu==upv) return;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
  public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[2]<=b[2];
    }
    map<vector<int>,vector<int>> mp;
    void create(vector<vector<int>> &queries){
        for(int i=0;i<queries.size();i++){
            mp[queries[i]].push_back(i);
        }
    }
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        //Initializing Stuff
        DisjointSet ds(n);
        create(queries);
        vector<bool> ans(queries.size());
        sort(queries.begin(),queries.end(),comp);
        sort(edgeList.begin(),edgeList.end(),comp);
        int j=0;

        //Creating DSU progressevily for sorted queries and edge list
        for(auto query:queries){
            int u=query[0];
            int v=query[1];
            int l=query[2];

            while(j<edgeList.size()){
                int s=edgeList[j][0];
                int e=edgeList[j][1];
                int w=edgeList[j][2];

                if(w<l)
                    ds.UnionRank(s,e);
                else break;
                j++;
            }
            bool result=ds.FindUParent(u)==ds.FindUParent(v);
            for(auto &index:mp[query])
                ans[index]=result;
        }
        return ans;
    }
};
