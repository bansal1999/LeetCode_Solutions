class Solution {
public:
    bool judgeCircle(string moves) {
        
        unordered_map<char, int> mp;
        
        for(auto it: moves)
        {
            mp[it]++;
        }
        
//         int upctr =0, rtctr = 0;
        
//         for(int i =0; i< moves.size(); i++)
//         {
//            if(moves[i] == 'U')
//                upctr++;
//             else if(moves[i] == 'D')
//                 upctr--;
            
//              if(moves[i] == 'R')
//                  rtctr++;
//             else if(moves[i] == 'L')
//                 rtctr--;
//         }
        
        if(mp['L'] == mp['R'] && mp['U'] == mp['D'])
            return true;
        else
            return false;
        
//         if(upctr == 0 && rtctr == 0)
//             return true;
//         else
//             return false;
       
    }
};