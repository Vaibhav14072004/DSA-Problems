class Solution {
public:
    bool validCode(string code)
    {
        if(code.empty()) return false;
        for(char ch: code)
        {
            if(!((ch>= 'a' && ch<= 'z') || (ch >= 'A' && ch<= 'Z') 
            || (ch>= '0' && ch<= '9') || (ch== '_')))
            {
                return false;
            }
        }
      return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        vector<string> ans;
        unordered_map<string, vector<string>> mp;

        for(int i=0; i<code.size(); i++)
        {
            if(validCode(code[i]) && isActive[i] && (businessLine[i]== "electronics" ||
            businessLine[i]== "grocery" || businessLine[i]== "pharmacy"
            || businessLine[i]== "restaurant"))
            {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> order= {"electronics", "grocery", "pharmacy", "restaurant"};
     
        for(auto it: order)
        {
            if(mp.count(it))
            {
               vector<string> temp= mp[it];
               sort(temp.begin(),temp.end());
               for(auto it: temp) ans.push_back(it);
            }    
        }
       return ans; 
    }
};