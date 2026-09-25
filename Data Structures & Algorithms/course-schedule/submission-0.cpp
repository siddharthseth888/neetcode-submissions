class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // graph[i] holds the list of courses that depend on course i
        vector<vector<int>> graph(numCourses);
        // indegree[i] holds the number of prerequisites course i has
        vector<int> indegree(numCourses, 0);

        // 1. Build the graph and the indegree array
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            
            graph[prereq].push_back(course);
            indegree[course]++; // course has one more prerequisite
        }

        // 2. Find all courses with 0 prerequisites and put them in a queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Process the queue
        int completedCourses = 0;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            completedCourses++; // We successfully took this course

            // Unlock the next courses
            for(int neighbor : graph[current]) {
                indegree[neighbor]--; // Remove 'current' as a requirement
                
                // If the neighbor now has 0 prerequisites, we can take it
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. Did we take all the courses?
        return completedCourses == numCourses;
    }
};