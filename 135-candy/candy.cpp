// Approach 3 -> Using Peak Technique
// TC= O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int i=1;
        int ans= n; // each student must get 1 candy

        while(i< n)
        {
            if(ratings[i]== ratings[i-1])
            {
                i++;
                continue;
            }

            int peak= 0;
            while(i< n && ratings[i] > ratings[i-1])
            {
                peak++;
                ans+= peak;
                i++;
            }

            int dip= 0;
            while(i< n && ratings[i] < ratings[i-1])
            {
                dip++;
                ans+= dip;
                i++;
            }
          ans-= min(peak,dip);
        }
    return ans;
    }
};







// Approach 2 -> Using only 1 extra vector
// TC= O(2*N)

/*

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> left(n,0);
        left[0]= 1;

        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                left[i]= 1 + left[i-1];
            }
            else
            {
                left[i]= 1;
            }
        }
        
        int sum= 0;
        int right= max(1, left[n-1]);
        sum+= right;

        for(int i= n-2; i>= 0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                right++;
            }
            else
            {
                right= 1;
            }
            sum+= max(left[i], right);
        }
    return sum;
    }
};

*/








// Approach 1 -> Using 2 extra vectors
// TC= O(3*N)

/*

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        vector<int> left(n,0);
        left[0]= 1;

        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                left[i]= 1 + left[i-1];
            }
            else
            {
                left[i]= 1;
            }
        }

        vector<int> right(n,0);
        right[n-1]= 1;

        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
               right[i]= 1+ right[i+1]; 
            }
            else
            {
                right[i]= 1;
            }
        }

        int sum= 0;
        for(int i=0; i<n; i++)
        {
            sum+= max(left[i],right[i]);
        }
      return sum;  
    }
};

*/