class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();

        for(auto &row:box){
            int cntEmpty=0;
            for(int j=n-1;j>=0;j--){
                if(row[j]=='.')cntEmpty++;
                else if(row[j]=='*')cntEmpty=0;
                else{
                    if(cntEmpty==0)continue;
                    row[j+cntEmpty]='#';
                    row[j]='.';
                }
            }
        }

        vector<vector<char>>res;

        for(int col=0;col<n;col++){
            vector<char>temp;
            for(int row=m-1;row>=0;row--){
                temp.push_back(box[row][col]);
            }
            res.push_back(temp);
        }

        return res;
    }
};