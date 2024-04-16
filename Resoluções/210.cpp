using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prescedence(numCourses);
        vector<int> order, count(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            prescedence[prerequisites[i][1]].push_back(prerequisites[i][0]);
            count[prerequisites[i][0]]++;    
        }
        
        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (count[i] == 0) q.push(i);

        while(!q.empty()) {
            int front = q.front();
            order.push_back(front);
            q.pop();
            
            for (auto val: prescedence[front]) {
                if (--count[val] == 0) {
                    q.push(val);
                }
            }
        }

        if (order.size() < numCourses)
            return {};
        else
            return order;
    }
};
