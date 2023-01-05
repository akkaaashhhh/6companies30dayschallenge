class Solution {
public:
    bool cyclecheck(int s, vector<bool>&visited, vector<bool>&visiting, vector<int>adj[])
    {
        visited[s]=true; // we set that it is already visited
        visiting[s]=true;  // we set that it is currently being visited

        vector<int>join = adj[s];
        for(auto x: join)
        {
            if(!visited[x])// if the node is not visited
            {
                if(cyclecheck(x,visited,visiting,adj))
                {
                    return true; //  we check if there is a cycle in the upcoming nodes
                }
            }
             else if(visited[x]&&visiting[x])
             {
                 return true; // this case specifies that if the element is already visited but is being visited again implying a cycle
             }
        }
        visiting[s]=false; // we set that it is not being visited anymore implying that the course has been completed via this node
        return false; // if there are no cycles despite the recursive check we return false for the cycle check.
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool>visited(n,false), visiting(n, false); //create a boolean vector which sets that the element has not been visited and is not being visited currently

        vector<int> adj[n];   
        for(auto x: prerequisites)
        { // this for loop makes a directed edge fromusing every set in the prereq list of lists.
            vector<int>join=x;
            int a = join[0];
            int b = join[1];
            adj[a].push_back(b);
        }
        for(int i=0;i<n;i++) // this for loop visits each and every node and checks for cycles using the concept of recursion.
        {
            if(!visited[i])
            {
                if(cyclecheck(i,visited,visiting,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};