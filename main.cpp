#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void remove_redundant(int x, int y, vector<int>& rank, vector<int>& parent){
        if(rank[x]<rank[y]) parent[x]=y;
        else if(rank[x]>rank[y]) parent[y]=x;
        else{
            parent[y]=x;
            rank[x]++;
        }
    }

    int findUpar(int node, vector<int>& parent){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node], parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> rank(n+1, 0); //un nodo mas
        vector<int> parent(n+1);
        int x, y;

        //arranca desde el segundo nodo
        for(int i=1; i<=n; i++) parent[i]=i; 
        for(auto it: edges){
            x=findUpar(it[0], parent); //primer nodo
            y=findUpar(it[1], parent); //segundo nodo del mismo vector
            if(x==y) return it;
            else remove_redundant(x, y, rank, parent);
        }
        return {};
    }
};

int main(){
    return 0;
}