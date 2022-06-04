class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        set<int>vr; set<int>vc;
        
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(matrix[i][j]==0) {
                    vr.insert(i);
                    vc.insert(j);
                }
            }
        }
        
        for(auto itr = vr.begin(); itr != vr.end(); itr++)  {
            for(int j=0;j<c;j++) matrix[*itr][j] = 0;
        }
        for(auto itc = vc.begin(); itc != vc.end(); itc++) {
            for(int j=0;j<r;j++) matrix[j][*itc] = 0;
        }
      vr.clear();vc.clear();
    }
};
