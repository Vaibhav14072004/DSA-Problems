class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<unordered_set<int>> dependentCourses;
    
    unordered_set<int> dfs(int from) {
        visited[from] = true;
        unordered_set<int> current{from};
        
        for (int to : graph[from]) {
            if (!visited[to]) {
                auto toSet = dfs(to);
                current.insert(toSet.begin(), toSet.end());
            } else {
                current.insert(to);
                current.insert(dependentCourses[to].begin(), dependentCourses[to].end());
            }
            dependentCourses[from].insert(current.begin(), current.end());
        }
        
        return current;
    }
    
    unordered_set<int> getRoots(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> result;
        for (int i = 0; i < numCourses; i++) {
            result.insert(i);
        }
        
        for (const auto& prereq : prerequisites) {
            result.erase(prereq[1]);
        }
        
        return result;
    }
    
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        graph.resize(numCourses);
        for (const auto& prereq : prerequisites) {
            graph[prereq[0]].push_back(prereq[1]);
        }
        
        visited.resize(numCourses, false);
        dependentCourses.resize(numCourses);
        
        auto roots = getRoots(numCourses, prerequisites);
        for (int from : roots) {
            if (!visited[from]) {
                dfs(from);
            }
        }
        
        vector<bool> result;
        result.reserve(queries.size());
        for (const auto& query : queries) {
            result.push_back(dependentCourses[query[0]].count(query[1]) > 0);
        }
        
        return result;
    }
};