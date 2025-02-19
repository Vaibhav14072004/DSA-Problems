/*
Traverse from end and find first index where arr[i-1] < arr[i]
Store the index (i-1) ->> gola_index

Now Traverse again from end, and swap the gola_index value with its just greater value that is found first
Then reverse all numbers after gola_index to its right...
*/

// TC= O(3*N)

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n= arr.size();

        // first find index (start from end and stop at arr[i-1] where arr[i-1] < arr[i])
        int gola_index= -1;

        for(int i=n-1; i>0; i--)
        {
            if(arr[i-1] < arr[i])
            {
                gola_index= i-1;
                break;
            }
        }

        // now Traverse from end and swap the gola index with its just greater element on right
        // then reverse all elements to its right
        if(gola_index != -1)
        {
            for(int i=n-1; i>= gola_index+1; i--)
            {
                if(arr[gola_index] < arr[i])
                {
                    swap(arr[gola_index],arr[i]);
                    break;
                }
            }
        }
       reverse(arr.begin()+ gola_index+1, arr.end());  
    }
};