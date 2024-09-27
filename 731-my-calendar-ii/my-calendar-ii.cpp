// Approach 1 -> Using ordered map...
// TC= O(N* log N)
// SC= O(N)

class MyCalendarTwo {
public:
    // Ordered map with Tc= O(log n)
    map<int,int> mp; 

    MyCalendarTwo(){    
    }
    
    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        
        int sum= 0;
        for(auto it: mp)
        {
           sum+= it.second;

        // if sum becomes 3 it means there is a triple booking... but before returning false make values of mp[start] mp[end] as it was before...

           if(sum > 2)
           {
              mp[start]--;
              mp[end]++;
              return false;
           }
        }
      return true;
    }
};







/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */