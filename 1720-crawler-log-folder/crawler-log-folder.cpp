// TC= O(N)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        
            int cnt= 0;
            for(auto str: logs)
            {
                if(str == "../")
                {
                     if(cnt >0)cnt--;
                }
            
            // skip that particular iteration on which we are standing...
                else if(str== "./")
                {
                    continue;
                }

                else
                {
                    cnt++;
                }
            }
        return cnt;
    }
};