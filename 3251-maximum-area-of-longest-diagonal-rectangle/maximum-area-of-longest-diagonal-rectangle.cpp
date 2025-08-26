// TC= O(N)

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n= dimensions.size();
        int prevDia= 0, area= 0;

        for(int i=0; i<n; i++)
        {
            int a= dimensions[i][0];
            int b= dimensions[i][1];

            int dia= a*a + b*b;
            if(dia > prevDia)
            {
                prevDia= dia;
                area= a*b;
            }
            else if(dia== prevDia)
            {
                area= max(area, a*b);
                prevDia= dia;
            }
        }
    return area;
    }
};

