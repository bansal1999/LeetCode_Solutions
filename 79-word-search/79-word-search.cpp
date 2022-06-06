class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i =0; i < row; i++){
            for(int j =0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(checkDFS(i, j, board, word, row, col, 0) == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool checkDFS(int currRow, int currCol, vector<vector<char>>& board, string word, int row, int col, int currIdx) {
        
        if(currIdx == word.size()){
            return true;
        }
        
        if(currRow < 0 || currCol < 0 || currRow >= row || currCol >= col || board[currRow][currCol] != word[currIdx] ){
            return false;
        }
        
        board[currRow][currCol] = '0';
        
        if(checkDFS(currRow + 1, currCol, board, word, row, col, currIdx+1) == true)
            return true;
        
        if(checkDFS(currRow - 1, currCol, board, word, row, col, currIdx+1) == true)
            return true;
        
        if(checkDFS(currRow, currCol + 1, board, word, row, col, currIdx+1) == true)
            return true;
        
        if(checkDFS(currRow, currCol - 1, board, word, row, col, currIdx+1) == true)
            return true;
        
        board[currRow][currCol] = word[currIdx];
        
        return false;
        
    } 
    
    
};