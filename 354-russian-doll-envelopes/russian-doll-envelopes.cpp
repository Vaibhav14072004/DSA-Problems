// Approach -> (DP + Binary Search)
// TC= O(N* Log N)

// [width, height] =>> sort by width in ascending order 
// if width is equal... then sort by height in descending order
// and then apply concept of longest Inc Subsequence on height...

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        // if width is same, sort in descending order of height
        if(a[0]== b[0]){
           return a[1] > b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n= envelopes.size();

        // sort in ascending order of width but if width is same then,in descending order of height
        sort(envelopes.begin(),envelopes.end(),cmp);

        // now apply BinarySearch + DP on height of [wi,hi] to find length of LIS
        vector<int> temp;
        temp.push_back(envelopes[0][1]);

        for(int i=0; i<n; i++)
        {
             if(!temp.empty() && envelopes[i][1] > temp.back())
             {
                temp.push_back(envelopes[i][1]);
             }

             // find first >= element than curr, and replace it with curr element in temp
             else
             {
                 int firstGreater= lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                 temp[firstGreater]= envelopes[i][1];
             }
        }
    return temp.size();
    }
};