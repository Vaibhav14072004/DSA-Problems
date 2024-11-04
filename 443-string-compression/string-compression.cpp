// TC= O(N)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        
        int index= 0, i= 0;
        while(i < n)
        {
            int cnt= 1;
            char curr= chars[i];
            while(i+1 < n && chars[i]== chars[i+1])
            {
                cnt++;
                i++;
            }

            chars[index]= curr;
            index++;
            
            // if cnt= 1 only, then append only the char, without the freq..
            if(cnt > 1)
            {
                string temp= to_string(cnt);
                // if cnt is of 2 digits, append each digit separately..
                for(char ch: temp)
                {
                    chars[index]= ch;
                    index++; 
                }
            }
            i++;
        }
        return index;
    }
};