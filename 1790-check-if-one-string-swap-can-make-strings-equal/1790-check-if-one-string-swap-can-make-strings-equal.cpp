class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffPos;
        
        for(int i =0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diffPos.push_back(i);
            }
            if(diffPos.size() > 2){
                return false;
            }
        }
        
        if(diffPos.empty()){
            return true;
        }
        
        if(diffPos.size() == 2){
            swap(s1[diffPos[0]] , s1[diffPos[1]]);
        }
        
        return s1 == s2;
    }
};