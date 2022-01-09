class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        
        int num = n, bit = 1;
        
        while(num != 0)
        {
            n = n^ bit;
            bit  = bit << 1;
            num = num >> 1;
        }
        
        return n;
    }
};