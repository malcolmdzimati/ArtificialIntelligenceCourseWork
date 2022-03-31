#include <iostream>
#include "Search.h"

using namespace std;


int main(int argc, char *argv[]) {
  int init[] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
  int go[] = {1, 3, 4, 8, 6, 2, 7, 0, 5};

  //int* initial = eish(init);
  //int* goal = eish(go);

  Node* goalState = new Node(go, 7, 0, NULL);
  Node* startState = new Node(init, 4, 0, goalState);

  //cout<<*(startState->getPuzzle()+2)<<initial[2]<<init[2]<<endl;
  Search* bfs = new Search(startState, goalState);

  cout<<"It took "<<bfs->breadthFS()<<" Number of iterations, with "<<goalState->getOptimum()<<" Optimum"<<endl;
  return 0;
}
