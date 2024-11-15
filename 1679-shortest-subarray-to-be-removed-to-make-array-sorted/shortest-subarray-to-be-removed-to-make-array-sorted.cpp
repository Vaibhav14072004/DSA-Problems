// Approach -> Using 2 Pointers
// TC= O(N)
// SC= O(1)

/*
    <<<<---- 3 Cases Arises  --->>>

1. Remove left portion     ...... _____
2. Remove right portion    __________ ......
3. Remove middle portion  _____ ...... _____
*/


class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n= arr.size();
        int i=0, j= n-1;
        
        while(j> 0 && arr[j-1] <= arr[j])
        {
            j--;
        }
        
        // Initialized with j, to handle the 1st case, remove left portion 
        int ans= j;

        while(i < j)
        {
            while(j< n && arr[i] > arr[j])
            {
                j++;
            }

            ans= min(ans, j-i-1);

            i++;
            if(arr[i-1] > arr[i])
            {
                break;
            }
        }

        return ans;
    }
};