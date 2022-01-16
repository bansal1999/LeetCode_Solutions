class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long cnt = 0;
        
        if(maxDoubles == 0)
            return target-1;
        
        while(target > 0 )
        {
            if(target % 2 == 0 && maxDoubles > 0)
            {
                target = target/2;
                maxDoubles -= 1;
                
            }
            else
            { 
                target -= 1;
               
            }
             cnt++;
            if(maxDoubles == 0)
                break;
            
           
        }
        return cnt + (target -1);
    }
};