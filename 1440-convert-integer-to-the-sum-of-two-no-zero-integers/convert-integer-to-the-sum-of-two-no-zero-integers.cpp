class Solution {
public:

 bool anyzero(int num){
    while(num>0){
        if(num%10 == 0) return true; //zero exist there 
        num/= 10;     
    }
    return false;
 }

 vector<int> getNoZeroIntegers(int n) { 
         for(int i =1 ;i<=n;i++){
             int a =i;
             int b = n-i;
             if(!anyzero(a) && !anyzero(b)){
                return {a,b};
             }
         }
return {};
    }
};