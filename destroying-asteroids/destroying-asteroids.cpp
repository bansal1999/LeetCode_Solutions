class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        long long runningMass = mass;
         long long n = asteroids.size();
        
        sort(asteroids.begin(), asteroids.end());
        
        for(long long i =0; i<n; i++)
        {
            if(asteroids[i] > runningMass)
                return false;
            else
                runningMass += asteroids[i];
        }
        
        return true;
    }
};