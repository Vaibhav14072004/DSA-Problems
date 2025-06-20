// TC= O(N)

class Solution {
public:
    int maxDistance(string str, int k) {
        int n= str.length();
        int maxDist= 0;

        int east= 0, west= 0, north= 0, south= 0;
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'E') east++;
            else if(str[i]== 'W') west++;
            else if(str[i]== 'N') north++;
            else south++;

            int dist= abs(north-south)+ abs(east-west);
            int totalSteps= i+1;

            int wasted= totalSteps-dist;
            
            int extra= 0;
            if(wasted > 0)
            {
                extra= min(wasted, 2*k);
            }
          maxDist= max(maxDist, extra + dist);
        }
      return maxDist;  
    }
};