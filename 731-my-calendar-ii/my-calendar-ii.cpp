// Approach 2 -> Using 2 separate vector for storing double Bookings and curr valid booking
// TC= O(2* N)
// SC= O(2* N)

// Condition for overlap... ->> (start < b && a < end)

//            a -------------- b
//  start -------------- end

//  OR We can also check, Condition for Overlap.. ->> max(start,a) < min(b,end)


class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleBook;
    vector<pair<int,int>> currBook;

    MyCalendarTwo(){    
    }
    
    bool book(int start, int end)
    {
        for(auto it: doubleBook)
        {
            // overlap...
            if(start < it.second && it.first < end)
            {
                return false;
            }
        }

        for(auto it: currBook)
        {
            // insert in double booking... if overlap
            if(start < it.second && it.first < end)
            {
                doubleBook.push_back({max(start, it.first), min(end, it.second)});
            } 
        }
        
        currBook.push_back({start,end});
        return true;
    }
};











// Approach 1 -> Using ordered map...
// TC= O(N* log N)
// SC= O(N)

/*

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

*/






/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */