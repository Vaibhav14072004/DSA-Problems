class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        int i=0, j=0, maxi= 0;
        unordered_map<int,int> mp;

        while(j < n)
        {
            mp[fruits[j]]++;

           // shrink the curr window if st.size() > 2
           while(i<j && mp.size() > 2)
           {
               mp[fruits[i]]--;
               if(mp[fruits[i]]== 0){
                   mp.erase(fruits[i]);
               }
               i++;
           }

           maxi= max(maxi,j-i+1);
           j++;
        }
     return maxi;   
    }
};