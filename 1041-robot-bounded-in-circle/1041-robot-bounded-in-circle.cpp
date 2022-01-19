class Solution {
public:
    bool isRobotBounded(string instructions) {
        char dir = 'N';
        int x =0, y =0;
        
        for(int i =0; i< instructions.size(); i++)
        {
            if(instructions[i] == 'G')
            {
                if(dir == 'N')
                    y += 1;
                else if(dir == 'S')
                    y -= 1;
                else if(dir == 'E')
                    x += 1;
                else
                    x -= 1;
            }
            else if(instructions[i] == 'L')
            {
                if(dir == 'N')
                    dir = 'W';
                
                else if(dir == 'S')
                    dir = 'E';
                else if(dir == 'W')
                    dir = 'S';
                else
                    dir = 'N';
            }
            else
            {
                if(dir == 'N')
                    dir = 'E';
                
                else if(dir == 'S')
                    dir = 'W';
                else if(dir == 'W')
                    dir = 'N';
                else
                    dir = 'S';
            }
            
            
        }
        
        if(x == 0 && y == 0)
            return true;
        if(dir == 'N')
            return false;
        
        return true;
        
    }
};