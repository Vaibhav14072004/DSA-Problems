// Approach 1 -> Binary Search
// TC= O[M* log(maxElement)]


class Solution{
public:
// Func to find no of partitions, if quantities[i] is divided into max of "mid" partitions
    int partitions(vector<int> &quantities, int mid, int n)
    {
        int m= quantities.size();
        int cnt= 0;
        
        for(int i=0; i<m; i++)
        {
            // ceil(a/b)=  (a+b-1)/b
           cnt+= ceil((float)quantities[i]/mid);
        }
        return cnt;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int maxi= *max_element(quantities.begin(),quantities.end());

        // Now apply binary search between 1 to maxElement 
        int start= 1;
        int end= maxi;  
        int ans= INT_MAX;

        while(start<= end)
        {
            int mid= start+ (end-start)/2;
            
           // n should be greater than no of partitions formed if 
           // quantities[i] is divided into max of "mid" partitions
            if(n >= partitions(quantities,mid,n))
            {
                ans= mid;
                end= mid-1;
            }
            else
            {
                start= mid+1;
            }
        }
    return ans;
    }
};








/*
class Solution {
public:
    bool possibleToDistribute(vector<int>& quantities, int shops, int x) {
        for(int &products : quantities) {

            shops -= (products + x - 1) / x;

            if(shops < 0) {
                return false;
            }
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int l = 1;
        int r = *max_element(begin(quantities), end(quantities));

        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(possibleToDistribute(quantities, n, mid)) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return result;
    }
};

*/