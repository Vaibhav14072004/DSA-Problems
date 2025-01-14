// Approach 4 -> Using unordered_set
// TC= O(N)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        vector<int> ans(n,0);

        unordered_set<int> st;
        int cnt= 0;

        for(int i=0; i<n; i++)
        {
            if(st.count(A[i]))
            {
                cnt++;
            }
            st.insert(A[i]);

            if(st.count(B[i]))
            {
                cnt++;
            }
            st.insert(B[i]);

            ans[i]= cnt;
        }
    return ans;
    }
};







// Approach 3 -> Optimized
// TC= O(N)

/*

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        vector<int> ans(n,0);
        
        // {no, cnt}
        unordered_map<int,int> mp;
        
        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            mp[A[i]]++;
            if(mp[A[i]]== 2) cnt++;

            mp[B[i]]++;
            if(mp[B[i]]== 2) cnt++;

            ans[i]= cnt;
        }
    return ans;
    }
};

*/






// Approach 2 -> Using 2 vectors
// TC= O(N^2)

/*

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        vector<int> ans(n,0);

        vector<bool> visitedA(n+1,false);
        vector<bool> visitedB(n+1,false);

        for(int i=0; i<n; i++)
        {
            int cnt= 0;
            visitedA[A[i]]= true;
            visitedB[B[i]]= true;

            for(int j=1; j<=n; j++)
            {
                if(visitedA[j]== true && visitedB[j]== true)
                {
                    cnt++;
                }
            }
            ans[i]= cnt;
        }
    return ans;
    }
};

*/







// Approach 1 
// TC= O(N^3)

/*

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        vector<int> ans(n,0);

        for(int i=0; i<n; i++)
        {
            int cnt= 0;
             for(int j=0; j<= i; j++)
             {
                 for(int k=0; k<= i; k++)
                 {
                    if(A[j]== B[k])
                    {
                        cnt++;
                    }
                 }
             }

             ans[i]= cnt;
        }
     return ans;   
    }
};

*/