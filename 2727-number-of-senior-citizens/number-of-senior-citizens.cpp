// Approach 2
// TC= O(N)

class Solution{
public:
    int countSeniors(vector<string>& details) {
        int cnt= 0;

        for(int i=0; i<details.size(); i++)
        {
            // subtracting - '0' converts it to str to integer...
            int age= (details[i][11]- '0')* 10 + (details[i][12]- '0');
            if(age > 60)
            {
                cnt++;
            }
        }
     return cnt;
    }
};






// Approach 1 -> USing substr method..
// TC= O(N)
// stoi is used to convert string into integer...

/*

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt= 0;

        for(int i=0; i<details.size(); i++)
        {
            // substr(Start Index, length)
            int age= stoi(details[i].substr(11,2));
            
            if(age > 60)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

*/
