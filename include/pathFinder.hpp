#ifndef PATHFINDER__
#define PATHFINDER__

class pathFinder
{
private:
    double** traffic;                     //traffic matrix
    double** distance;                    // disatnce matrix
    int graphSize = 1;
    int* previous;                        // pointing to an array that keeps the previous node
    double pathFinderAlgorithm(int);      // an algoritm that find the best path
    int minDistance(double[], bool[]);

public:
    pathFinder(double**, double**, int);  //constructor 
    ~pathFinder();                        //destructor 
    void leastTraffic();                  // showing the least traffic path
    void leastDistance();
    void bestWay();
    void printPath(int[]);
};



#endif // PATHFINDER__
