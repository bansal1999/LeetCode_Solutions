// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	     unordered_map<char,int> umap;
    int i=0,j=0,k=pat.length(),ans=0;
    for(int l=0;l<pat.length();l++){
        umap[pat[l]]++;
    }
    int count=umap.size();
    while(j<txt.length()){
        if(umap.find(txt[j])!=umap.end()){
            umap[txt[j]]-=1;
            if(umap[txt[j]]==0){
                count-=1;
            }
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(count==0){
                ans+=1;
            }
            if(umap.find(txt[i])!=umap.end()){
                umap[txt[i]]+=1;
                if(umap[txt[i]]==1){
                    count+=1;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends