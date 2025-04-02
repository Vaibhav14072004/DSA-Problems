// TC= O(N)

class Solution {
public:
    vector<int> partitionLabels(string str) {
        int n= str.length();
        vector<int> ans;
        vector<int> lastOcc(26,-1);

        for(int i=0; i<n; i++)
        {
            lastOcc[str[i]-'a']= i;
        }

        int i=0;
        while(i < n)
        {
            int end= lastOcc[str[i]-'a'];
            for(int j=i; j<end; j++)
            {
                end= max(end, lastOcc[str[j]-'a']); 
            }
        
            ans.push_back(end-i+1);
            if(end== n-1){
                break;
            }
            
            i= end+1;
        }
    return ans;
    }
};