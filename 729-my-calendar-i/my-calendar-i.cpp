//          start ----------- end
//     a --------------- b  

// Condition for overlapping ->> (start < b && a < end)


// Approach 3 -> Using lower_bound()
// TC= O(log n)
// SC= O(n)


class MyCalendar {
public:
   set<pair<int,int>> st;

    MyCalendar() { 
    }
    
    bool book(int start, int end)
    {
      // lower_bound() ->> to find just greater equal element...
      auto it= st.lower_bound({start,end});
      
      // check for next value..
      if(it != st.end() && it->first < end)
      {
         return false;
      }
      
      // check for prev value...
      if(it != st.begin() && prev(it)->second > start)
      {
        return false;
      }

      st.insert({start,end});
      return true;
    }
};








// Approach 2 -> Using vector<pair<int,int> 
// TC= O(N)

/*

class MyCalendar {
public:
    vector<pair<int,int>> vec;

    MyCalendar() { 
    }
    
    bool book(int start, int end) {
        for(auto it: vec)
        {
            if(start < it.second && it.first < end)
            {
                return false;
            }
        }

        vec.push_back({start,end});
        return true;
    }
};

*/









// Approach 1 -> Using ordered_map
// TC= O(N log N)

// NOTE ->> We CANNOT use unordered_map bcoz it doesn't maintain any specific order of elements, and you need the map to be sorted by the event start times so we use ordered_map (map)

/*

class MyCalendar {
public:
   // Ordered_map with TC= O(log n)
    map<int,int> mp;

    MyCalendar() {
        
    }
    
    bool book(int start, int end)
    {
        // start-> +1    end-> -1
        mp[start]++; 
        mp[end]--;

        int sum= 0;
        for(auto it: mp)
        {
            sum+= it.second;

            // if there is overlapping sum would become 2 ...
            if(sum > 1)
            {
              // we are not adding this event in our ans, but we have incremented decremented above, so neutralize it
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 