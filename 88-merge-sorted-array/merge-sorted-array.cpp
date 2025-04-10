// Approach 3 -> Using GAP Method (Shell Sorting)
// Take i and j at gap of ceil (n+m/2.0)

// TC= O[(N+M)* log 2 (M+N)]

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
       // In ques it is given that nums1 is of len-> (n+m)
       for(int i=0; i<n; i++){
           nums1[i+m]= nums2[i];
       }

       int len= m+n;

       // take a gap => ceil [(n+m)/2] between i and j 
       int gap= len/2 + (len % 2);

       while(gap > 0)
       {
           int i=0;
           int j= i+gap;

           while(j < len)
           {
               if(nums1[i] > nums1[j]){
                   swap(nums1[i],nums1[j]);
               }
               i++;
               j++;
           }

           if(gap== 1) break;

           gap= gap/2 + (gap % 2);
       }
    }
};







// Approach 2 -> Without using extra space + Sorting
// Start from end of arr1 and start of arr2 

// TC= O(min(N,M)) + O(N log N) + O(M log M)

/*

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i= m-1;
        int j= 0;

        while(i>= 0 && j < n)
        {
            if(nums1[i] > nums2[j])
            {
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }

            // if nums1[i] <= nums2[j] , then all elements before i and after j is already sorted
            else
            {
                break;
            }
        }
        
        // in ques it is given that nums1 has (n+m) length having 0 appended in last
        // we have to sort only upto length m
        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        
        for(int i=0; i<n; i++)
        {
            nums1[i+m]= nums2[i];
        }
    }
};

*/







// Approach 1 -> Using extra space + 2 Pointers
// TC= O(M+N)

/*

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int merged[n+m];

        int i=0, j=0, idx= 0;
        while(i< m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                merged[idx++]= nums1[i++];
            }
            else
            {
                merged[idx++]= nums2[j++];
            }
        }

        // if nums1 is finished but nums2 is NOT
        while(j < n)
        {
            merged[idx++]= nums2[j++];
        }

        // if nums2 is finished but nums1 is NOT
        while(i < m)
        {
            merged[idx++]= nums1[i++];
        }

        // now copy elements of merged into nums1 
        for(int i=0; i<n+m; i++)
        {
            nums1[i]= merged[i];
        }
    }
};

*/