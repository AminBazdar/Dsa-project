
#include <iostream>
#include "pathFinder.hpp"

using namespace std;

int main()
{
   // matix of the graph
   double pathTraffic[16][16] = {{0, 1, 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                                 {1, 0, 2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                                 {1, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 2, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 3, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 2, 0, 3, 0, 0, 2, 0, 0, 0, 0},
                                 {0, 0, 0, 2, 0, 0, 0, 3, 0, 3, 1, 0, 0, 0, 0, 0},
                                 {3, 3, 2, 0, 0, 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 1},
                                 {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 1, 3, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 2},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0}};

   double pathDistance[16][16] = {{0, 0.2, 0.2, 0, 0, 0, 0, 0, 0, 0.2, 0, 0, 0, 0, 0, 0},
                                  {0.2, 0, 1.4, 0, 0, 0, 0, 0, 0, 1.3, 0, 0, 0, 0, 0, 0},
                                  {0.2, 1.4, 0, 2.4, 0, 0, 0, 0, 0, 0.2, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 2.4, 0, 3, 0, 0, 0, 1.9, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 3, 0, 4.1, 0, 0.1, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 4.1, 0, 1.2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 1.2, 0, 3.5, 0, 0, 0, 0, 0.8, 0, 0, 0},
                                  {0, 0, 0, 0, 0.1, 0, 3.5, 0, 0.1, 0, 0, 0.1, 0, 0, 0, 0},
                                  {0, 0, 0, 1.9, 0, 0, 0, 0.1, 0, 2.1, 2, 0, 0, 0, 0, 0},
                                  {0.2, 1.3, 0.2, 0, 0, 0, 0, 0, 2.1, 0, 1.9, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 2, 1.9, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0.1, 0, 0, 0, 0, 2, 0, 0, 0.1},
                                  {0, 0, 0, 0, 0, 0, 0.8, 0, 0, 0, 0, 2, 0, 0.2, 0.6, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.2, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.6, 0, 0, 1.8},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 0, 1.8, 0}};

   double** trafficPtr = new double* [sizeof(pathTraffic)/sizeof(pathTraffic[0])];
   double** distancePtr = new double* [sizeof(pathTraffic)/sizeof(pathTraffic[0])];
   for (size_t i = 0; i < sizeof(pathTraffic)/sizeof(pathTraffic[0]); i++)
   {
      trafficPtr[i] = pathTraffic[i];
      distancePtr[i] = pathDistance[i];
   }
   pathFinder resToUni(trafficPtr, distancePtr, (int)sizeof(pathTraffic)/sizeof(pathTraffic[0]));

   int command = 0;
   while (command != 4)
   {
      cout << "1: least traffic way.\n2: least distance way.\n3: best way\n4: exit" << endl;
      cin >> command;
      switch (command)
      {
      case 1:
         resToUni.leastTraffic();
         break;
      case 2:
         resToUni.leastDistance();
         break;
      case 3:
         resToUni.bestWay();
         break;
      }
   }
   return 0;
}