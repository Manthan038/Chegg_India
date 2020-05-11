#include <iostream>
#include <list>

using namespace std;

class Graph {      // class of Graph
  int numVertices;
  list<int>* adjLists;
  bool* visited;
  bool* visitedD;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void DFS(int startVertex);
  void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}


// DFS algorithm
void Graph::DFS(int startVertex) {
  visited[startVertex] = true;
  list<int> adjList = adjLists[startVertex];

  cout <<"Visited "<<startVertex<< " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

// BFS algorithm
void Graph::BFS(int startVertex) 
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}



int main() {
    int a,b,source,node,num,choice;
    cout<<"Enter Number of Node between 0 to 20\n";   // I supposed here that user will enter number betweeb the range
    cin>>node;                    /// here if user enter 5 then the node will 0,1,2,3,4
  Graph g(node);
  cout<<"Enter number of Edge you want in your graph\n";
  cin>>num;
  cout<<"Enter Vertex  a Space vertex b  for edge from a to b[Note: 0 <= a,b <Node Number\n";
   for(int i=0;i<num;i++)
   {
       cin>>a>>b;
       g.addEdge(a, b);
   }
   
   
  cout<<"Enter \t1. For DFS \n\t\t2. For BFS\n";
  cin>>choice;
  if (choice==1)
  {
  cout<<"For Depth first Search Enter Source Vertex:\n";
  cin>>source;
  g.DFS(source);
  }
  else
  {
  cout<<"\n\nFor Breath first Search Enter Source vertex:\n";
  cin>>source;
  g.BFS(source);
  }
  
  return 0;
}
