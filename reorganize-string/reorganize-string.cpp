class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> maxH;
        
        for(int i=0; i< s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        
        for(auto i: mp)
            maxH.push(make_pair(i.second, i.first));
        
        while(maxH.size() > 1)
        {
            auto top1 = maxH.top();
            maxH.pop();
            auto top2 = maxH.top();
            maxH.pop();
            
            res += top1.second;
            res += top2.second;
            
            top1.first -= 1;
            top2.first -= 1;
            
            if(top1.first > 0)
                maxH.push(top1);
            if(top2.first  > 0)
                maxH.push(top2);
        }
        
        if(!maxH.empty())
        {
            if(maxH.top().first > 1)
                return "";
            else
                res+=maxH.top().second;
        }
        
        return res;
        
    }
};