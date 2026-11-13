class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int sr = 0;
        int sc = 0;
        int er = matrix.size()-1;
        int ec = matrix[0].size()-1;

        while(sr <= er and sc <= ec){
            for(int j = sc; j <= ec; j++){
                res.push_back(matrix[sr][j]);
            }
            sr++;

            for(int i = sr; i <= er; i++){
                res.push_back(matrix[i][ec]);
            }
            ec--;

            if(sr <= er){
                for(int j = ec; j >= sc; j--){
                    res.push_back(matrix[er][j]);
                }
                er--;
            }

            if(sc <= ec){
                for(int i = er; i >= sr; i--){
                    res.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        return res;
    }
};
