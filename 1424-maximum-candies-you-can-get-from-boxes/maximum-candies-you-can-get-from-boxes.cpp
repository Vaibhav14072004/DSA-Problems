// Approach 2 -> Using BFS
// TC= O(N) 

class Solution{
  public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) { 

       unordered_set<int> visited;
       unordered_set<int> foundSet;
       int cnt= 0;

       queue<int> q;
       for(int &currBox: initialBoxes)
       {
           if(status[currBox]== 1){
               q.push(currBox);
           }

           // if status[currBox]== 0, means its key is not known
           else{
              foundSet.insert(currBox);
           }
       }

       while(!q.empty())
       {
           int currBox= q.front();
           q.pop();

           if(visited.count(currBox)){
              continue;
           }
           
           visited.insert(currBox);
           cnt+= candies[currBox];

           for(auto &it: containedBoxes[currBox])
           {
               if(!visited.count(it) && status[it]== 1)
               {
                   q.push(it);
               }
               else
               {
                  foundSet.insert(it);
               }
           }

           for(auto &it: keys[currBox])
           {
                status[it]= 1;
               if(!visited.count(it) && foundSet.count(it))
               {
                  q.push(it);
               }
           }
       }
     return cnt;  
    }
};






// Approach 1 -> Using DFS
// TC= O(N) -> Visited all boxes only at 1 time

/*

class Solution {
public:
    int DFS(int currBox, vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, unordered_set<int> &visited, unordered_set<int> &foundSet)
    {
        if(visited.count(currBox)){
            return 0;
        }

        if(status[currBox]== 0)
        {
           foundSet.insert(currBox);
           return 0;
        }

        visited.insert(currBox);
        int cnt= candies[currBox];

        for(auto &it: containedBoxes[currBox])
        {
            cnt+= DFS(it,status,candies,keys,containedBoxes,visited,foundSet);
        }

        for(auto &it: keys[currBox])
        {
            status[it]= 1;
            if(foundSet.count(it))
            {
                cnt+= DFS(it,status,candies,keys,containedBoxes,visited,foundSet);
            }
        }
      return cnt;  
    }


    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        // set for storing that boxes that are visited, key is known
        unordered_set<int> visited;
        
        // set for storing that boxes that are found, but key is NOT known
        unordered_set<int> foundSet;

        int cnt= 0;
        for(int currBox: initialBoxes)
        {
            if(!visited.count(currBox))
            {
                cnt+= DFS(currBox,status,candies,keys,containedBoxes,visited,foundSet); 
            }
        }
       return cnt; 
    }
};

*/