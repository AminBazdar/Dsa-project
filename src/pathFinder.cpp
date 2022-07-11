#include <iostream>
#include "pathFinder.hpp"

using namespace std;

pathFinder::pathFinder(double** traffic, double** distance, int size)
{
    this->traffic = traffic;
    this->distance = distance;
    this->graphSize = size;
    this->previous = new int[size];
}

pathFinder::~pathFinder()
{
    delete [] previous;
    delete [] traffic;
    delete [] distance;
}

double pathFinder::pathFinderAlgorithm(int code)
{
    double graph[graphSize][graphSize];
    switch (code)
    {
    case 1:
        for (size_t i = 0; i < graphSize; i++)
        {
            for (size_t j = 0; j < graphSize; j++)
            {
                graph[i][j] = traffic[i][j];
            }
        }
        break;
    case 2:
        for (size_t i = 0; i < graphSize; i++)
        {
            for (size_t j = 0; j < graphSize; j++)
            {
                graph[i][j] = distance[i][j];
            }
        }
        break;

    case 3:
        for (size_t i = 0; i < graphSize; i++)
        {
            for (size_t j = 0; j < graphSize; j++)
            {
                graph[i][j] = traffic[i][j] * distance[i][j]; 
            }
        }
        break;
    }
    double dist[graphSize];    // The output array.  dist[i] will hold the shortest 
                               // distance from src to i 
   
    bool sptSet[graphSize]; // sptSet[i] will be true if vertex i is included in shortest 
    //double path[graphSize];

    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < graphSize; i++) 
    {
        dist[i] = INT_MAX, sptSet[i] = false;         
    }
   
     // Distance of source vertex from itself is always 0 
    dist[0] = 0; 
   
     // Find shortest path for all vertices 
    for (int count = 0; count < graphSize-1; count++) 
    { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < graphSize; v++) 
        {  
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];          
                previous[v]= u;
            }
        }
    }
    return dist[13];        //in this case the 13th node is the distination
}

int pathFinder::minDistance(double dist[], bool sptSet[])
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < graphSize; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index;
}

void pathFinder::leastTraffic()             //least traffic
{  
    double pathCost = pathFinderAlgorithm(1);
    int path[graphSize];
    cout << "The cost of least traffic path is: " << pathCost << endl;
    printPath(path);
}

void pathFinder::leastDistance()            //least distance
{
    double pathCost = pathFinderAlgorithm(2);
    int path[graphSize];
    cout << "The cost of least distance path is: " << pathCost << endl;
    printPath(path);
}

void pathFinder::bestWay()              // best way at all
{
    double pathCost = pathFinderAlgorithm(3);
    int path[graphSize];
    cout << "The cost of best way is: " << pathCost << endl;
    printPath(path);
}

void pathFinder::printPath(int path [])         // showing the path
{
    for (size_t i = 0; i < graphSize; i++)
    {
        path[i] = -1;
    }

    int end = 13, i = 14;
    path[15] = 13; 
    while (end != 0)
    {
        path[i] = previous[end];
        end = previous[end];
        --i;
    }
    cout << "The path is: " << endl;
   for (size_t i = 0; i < graphSize; i++)
   {
      if (path[i] == -1)
      {
         continue;;
      }

      cout << path[i] << "\t";
   }
   cout << "\n-----------------------------------" << endl;
}