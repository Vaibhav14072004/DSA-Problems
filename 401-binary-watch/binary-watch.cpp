// TC= O(12*60)

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<string> ans;
        for(int hr=0; hr<12; hr++)
        {
            for(int min=0; min<60; min++)
            {
                if(__builtin_popcount(hr)+ __builtin_popcount(min) == turnedOn)
                {
                    string temp= to_string(hr);
                    temp+= ':';

                    if(min < 10)
                    {
                        temp+= '0';
                    }
                   
                    temp+= to_string(min);
                    ans.push_back(temp);
                }
            }
        }
      return ans;  
    }
};