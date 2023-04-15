#include<bits/stdc++.h>
using namespace std;
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
            rank[upu]+=size[upv];
        }
    }
};
int main(){
    cout<<"Enter the Number of Nodes : ";
    int size;
    cin>>size;
    DisjointSet ds(size);
    
    cout<<"\nEnter the edges : "<<endl;
    for(int i=0;i<size;i++){
        int u,v;
        cin>>u>>v;
        ds.UnionSize(u,v);
    }

    int u1,v1;
    cout<<"Enter the nodes for which you wanna check : "<<endl;
    cin>>u1>>v1;
    int p1=ds.FindUParent(u1);
    int p2=ds.FindUParent(v1);

    if(p1==p2)
        cout<<"Yes they belong to same Component . "<<endl;
    else cout<<"They Donot belong to same component . "<<endl;
}
