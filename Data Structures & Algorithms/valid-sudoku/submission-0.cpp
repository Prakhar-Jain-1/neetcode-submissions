class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[9] = {0};
        for(vector<char> s:board){
            fill(check, check + 9, 0);
            for(char c:s){
                if(c!='.'){
                    if(++check[c-'1'] == 2) return false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            fill(check, check + 9, 0);
            for(int j = 0; j<9;j++){
                char c = board[j][i];
                if(c!='.'){
                    if(++check[c-'1'] == 2) return false;
                }
            }
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j<9;j+=3){
                fill(check, check + 9, 0);
                for(int k = 0; k<3;k++){
                    for(int o =0; o<3;o++){
                        char c = board[i+k][j+o];
                        if(c!='.'){
                            if(++check[c-'1'] == 2) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
