#include <iostream>
#include "Search.h"

using namespace std;


int main(int argc, char *argv[]) {
  int init[] = {8, 6, 7, 2, 5, 4, 3, 0, 1};
  int go[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

  //int* initial = eish(init);
  //int* goal = eish(go);

  Node* goalState = new Node(go, 8, 0, NULL);
  Node* startState = new Node(init, 7, 0, goalState);

  //cout<<*(startState->getPuzzle()+2)<<initial[2]<<init[2]<<endl;
  Search* bfs = new Search(startState, goalState);

  cout<<"It took "<<bfs->breadthFS()<<" Number of iterations, with "<<goalState->getOptimum()<<" Optimum"<<endl;
  return 0;
}
