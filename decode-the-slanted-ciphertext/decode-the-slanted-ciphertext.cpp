class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = encodedText.size();
        int cols =  n/ rows;
        
        vector<vector<char>> mat(rows, vector<char>(cols));
        
        int k = 0;
        
        for(int i =0; i< rows; i++)
        {
            for(int j =0; j< cols; j++)
            {
                mat[i][j] = encodedText[k++];
            }
        }
        
        string original = "";
        
        for(int j = 0; j< cols; j++)
        {
            int r =0;
            int c = j;
            
            while(r < rows and c < cols)
            {
                original += mat[r++][c++];
            }
        }
        
        while(original.back() == ' ')
            original.pop_back();
        
        
        return original;
            
    }
};