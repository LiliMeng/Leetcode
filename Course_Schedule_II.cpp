class Graph
{
    int V;
    list<int>* adj;
    int* indegree;
    queue<int> q;
public:
    vector<int> vec;
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool topological_sort();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
    indegree= new int[V];
    for(int i=0; i<V; i++)
    {
        indegree[i]=0;   
    }
}

Graph::~Graph()
{
    delete [] adj;
    delete [] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    indegree[w]++;
}

bool Graph::topological_sort()
{   
    for(int i=0; i<V; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    

    int count=0;
   
    while(!q.empty())
    {   
        int v=q.front();
        q.pop();
        
        vec.push_back(v);
        count++;
        
        for(auto ite=adj[v].begin();ite!=adj[v].end();ite++)
        {
            indegree[*ite]--;
            if(indegree[*ite]==0)
            {
                q.push(*ite);
            }
        }
    }
    
    if(count<V)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        
        for(int i=0; i<prerequisites.size();i++)
        {
            g.addEdge(prerequisites[i].second,prerequisites[i].first);
        }
        
        if(g.topological_sort())
        {
            return g.vec;
        }
        else
        {
            return vector<int>();
        }
        
    }
};
