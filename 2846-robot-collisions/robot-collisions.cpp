// Aproach -> Using sorting
// TC= O(N log N)

class Solution {
 public:
     
    /* If we write static bool cmp, then it will error bcoz it expects only 2 parameters,
     use instead of it, we use lambda function directly inside sort()....

    static bool cmp(int i,int j,vector<int> &positions)
        return positions[i] < positions[j]; */


    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n= positions.size();
        vector<int> indexes(n);

        for(int i=0; i<n; i++)
        {
            indexes[i]= i;
        }

        // sort indices based on ascending order of positions.. and write lambda func inside
        sort(indexes.begin(),indexes.end(), [&](int a, int b)
        {
            return positions[a] < positions[b];
        });
        
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            int idx= indexes[i];

            // if it is moving in left direction..
            if(directions[idx] == 'L')
            {
                   while(!st.empty() && directions[st.top()]== 'R')
                   {
                        if(healths[st.top()] > healths[idx])
                        {
                            healths[st.top()]--;
                            healths[idx]= 0;
                            break;
                        }
                        
                        else if(healths[st.top()] < healths[idx])
                        {
                            healths[idx]--;
                            healths[st.top()]= 0;
                            st.pop();
                        }   
                        
                        // if healths[st.top()]== healths[idx]
                        else
                        {
                            healths[st.top()]= 0;
                            healths[idx]= 0;
                            st.pop();
                            break;
                        }  
                   } 

                   if(healths[idx] > 0)
                   {
                       st.push(idx);
                   }
            }

            // if it is moving in 'R' direction, just push in stack
            else
            {
                st.push(idx);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(healths[i] > 0)
            {
               ans.push_back(healths[i]);
            }
        }
    return ans;
    }
};







/*
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int index = 0; index < n; ++index) {
            indices[index] = index;
        }

        sort(indices.begin(), indices.end(),
             [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });

        for (int currentIndex : indices) {
            // Add right-moving robots to the stack
            if (directions[currentIndex] == 'R') {
                stack.push(currentIndex);
            } else {
                while (!stack.empty() && healths[currentIndex] > 0) {
                    // Pop the top robot from the stack for collision check
                    int topIndex = stack.top();
                    stack.pop();

                    // Top robot survives, current robot is destroyed
                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        // Current robot survives, top robot is destroyed
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        // Both robots are destroyed
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots
        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};

*/