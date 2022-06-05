// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
     bool solve(int src, vector<bool>&vis, vector<int>&order, vector<int>adj[]){
       vis[src]=true;
       order[src]=1;
       for(auto x : adj[src]){
           if(!vis[x]){
               bool conf=solve(x,vis,order,adj);
               if(conf==true) return true;
           }
           else if(order[x]) return true;
       }
       order[src]=0;
       return false;
   }
   bool isCyclic(int v, vector<int> adj[]) {
       vector<bool>vis(v,0);
       vector<int>order(v,0);
       for(int i=0; i<v; i++){
           if(!vis[i]){
               bool c=solve(i,vis,order,adj);
               if(c==true)
               return true;
           }
       }
       return false;
   }
};


  
//   bool dfsHelper(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis){
//       vis[node] = 1;
//       dfsVis[node] = 1;
      
//       for(auto it: adj[node]){
//           if(!vis[it]){
//               if(dfsHelper(it, adj, vis, dfsVis)){
//                   return true;
//               }
//           }
//           else if(dfsVis[node]){
//               return true;
//           }
//       }
//       dfsVis[node] = 0;
//       return false;
//   }
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//         // code here
//         vector<bool> vis(V, 0);
//         vector<bool> dfsVis(V, 0);
        
//         for(int i =0; i< V; i++){
//             if(!vis[i]){
//                 if(dfsHelper(i, adj, vis, dfsVis)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends