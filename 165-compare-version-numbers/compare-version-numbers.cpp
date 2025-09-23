class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1= version1.size();
        int n2= version2.size();
        vector<string> vec1, vec2;

        stringstream ss1(version1);
        string token= "";

        // while(ss1 >> token)
        while(getline(ss1,token,'.'))
        {
            vec1.push_back(token);
        }

        stringstream ss2(version2);
        while(getline(ss2,token,'.'))
        {
            vec2.push_back(token);
        }
        
        int i=0;
        while(i<vec1.size() || i<vec2.size())
        {
            int a= 0, b= 0;
            if(i< vec1.size()){
                a= stoi(vec1[i]);
            }

            if(i< vec2.size()){
                b= stoi(vec2[i]);
            }

            if(a<b) return -1;
            else if(a> b) return 1;
            else i++;
        }
      return 0;  
    }
};