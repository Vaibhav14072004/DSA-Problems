// Correct Approach 
// TC= O(N)

class Solution{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n= digits.size();
        for(int i=n-1; i>=0; i--)
        {
            // if digits[i] < 9 directly increment it and return;
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
           digits[i]= 0; 
        }

        // push '1' at the beginning
        digits.insert(digits.begin(),1);
      return digits;  
    }
};





/* ----- WRONG APPROACH (RUN TIME ERROR) ------
This approach will always give runtime error, as there can be 100+ digits in a no
and it will exceed of size of even long long also
 
// Wrong Approach -> first making no, then increasing it by one
// TC= O(N)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n= digits.size();

        int no= 0;
        int j=0;
        for(int i=n-1; i>=0; i--)
        {
            no+= (pow(10,j) * digits[i]);
            j++;
        }
     
      no++;
      string str= to_string(no);
      vector<int> ans;
      for(int i=0; i<str.size(); i++)
      {
          ans.push_back(str[i]-'0');
      }
      return ans;
    }
};
*/