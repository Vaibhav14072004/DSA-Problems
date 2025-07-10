class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray;
        freeArray.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freeArray.push_back(startTime[i]-endTime[i-1]);
        }
        freeArray.push_back(eventTime-endTime[endTime.size()-1]);
        int n=freeArray.size();
        vector<int> rightFree(n,0);
        vector<int> leftFree(n,0);
        for(int i=n-2;i>=0;i--){
            rightFree[i] = max(rightFree[i+1],freeArray[i+1]);
        }
        for(int i=1;i<n;i++){
            leftFree[i] = max(leftFree[i-1],freeArray[i-1]);
        }
        int result = 0;
        for(int i=1;i<n;i++){
            int currEventTime = endTime[i-1]-startTime[i-1];
            if(currEventTime <= max(leftFree[i-1],rightFree[i])){
                result = max(result,freeArray[i-1]+currEventTime+freeArray[i]);
            }
            result = max(result,freeArray[i-1]+freeArray[i]);
        }
        return result;
    }
};