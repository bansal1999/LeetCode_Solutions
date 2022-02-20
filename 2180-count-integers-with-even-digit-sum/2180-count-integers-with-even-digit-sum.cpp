class Solution {
public:
    int countEven(int num) {
        
        int cnt =0;
        
        for(int ele = 1; ele<= num; ele++)
        {
            int digi = 0;
            int p = ele;
            
            while(p != 0)
            {
                int n = p%10;
                digi += n;
                p /= 10;
                
            }
            
            if(digi % 2 ==0)
                cnt++;
        }
        return cnt;
    }
};