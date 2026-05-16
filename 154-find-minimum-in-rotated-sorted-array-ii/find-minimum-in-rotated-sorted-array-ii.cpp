class Solution {
public:
    int findMin(vector<int>& arr) {
        int n= arr.size();

        int start= 0;
        int end= n-1;
        int ans= INT_MAX;

        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            ans = min(ans, arr[mid]);

         // Handle duplicates...
            if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
                start++;
                end--;
                continue;
            }


    // If left half sorted...
    if(arr[start] <= arr[mid])
    {
      ans= min(ans, arr[start]);
      start= mid+1;
    }   

    // Right half sorted...if(arr[mid] <= arr[end])
    else
    {
       //  ans= min(ans, arr[mid]);
        end= mid-1;
    }
        }
    return ans;
    }
};