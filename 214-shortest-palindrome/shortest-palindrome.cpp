class Solution {
public:

   vector<int> solve(string A){
    
     int  n =A.size();
     vector<int> lps(n);
    lps[0]=0;
    int len =0;
    int i=1;
    
    while(i<n){
        
        if(A[i]==A[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            
            
            if(len==0){
                lps[i]=0;
                i++;
            }else{
                len=lps[len-1];
            }
        }
    }

    return lps;
}
    string shortestPalindrome(string s) {

        string a =s;
        reverse(a.begin(),a.end());

        string r =s;
        r+='*';
        r+=a;
        vector<int> lps =solve(r);


        int len = s.size()-lps.back();
       
         a= s.substr(s.size()-len,len);
         reverse(a.begin(),a.end());
         return a+s;

        return a;
    }
};