class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();

        // Creating a stack of map and pushing an empty map
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while(i < n)
        {
            if(formula[i] == '(') // A new sub-element has started
            {
                // Push an empty map into the stack
                st.push(unordered_map<string, int>());
                i++;
            }
            else if(formula[i] == ')')
            {
                // Remove the top map
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                // After ')' there will be a number
                // We have to multiply all the elements in 'curr' by the number
                // Then combine it with the map below it which will be its parent map

                string mult = "";
                while(i < n && isdigit(formula[i]))
                {
                    mult += formula[i];
                    i++;
                }

                // Multipyling all the elements' count by the multiplier
                if(mult.size() != 0)
                {
                    int multInteger = stoi(mult);
                    for(auto &it: curr)
                    {
                        string ele = it.first;
                        curr[ele] = it.second * multInteger;
                    }
                }

                // Merge with the map below
                for(auto &it: curr)
                {
                    string ele = it.first;
                    int count = it.second;
                    st.top()[ele] += count;
                }
            }
            else // It is a letter thus start of an element
            {
                string currElement = "";
                currElement += formula[i];
                i++;

                // It is the same element if the subsequent characters are in lower case
                while(i < n && isalpha(formula[i]) && islower(formula[i]))
                {
                    currElement += formula[i];
                    i++;
                }

                string currCount = "";
                while(i < n && isdigit(formula[i]))
                {
                    currCount += formula[i];
                    i++;
                }

                int currCountInt = currCount.size() == 0 ? 1 : stoi(currCount);
                st.top()[currElement] += currCountInt;
            }
        }

        map<string, int> sortedMap(st.top().begin(), st.top().end());
        st.pop();

        string result = "";
        for(auto it: sortedMap)
        {
            string ele = it.first;
            result += ele;

            int count = it.second;
            if(count > 1)
                result += to_string(count);
        }

        return result;
    }
};