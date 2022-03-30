#include <iostream>
#include "Search.h"

using namespace std;

/*int* eish(int i[9]){
  int* ii = new int[9];
  for(int x; x < 9; x++){
    ii[x] = i[x];
  }
  return ii;
}*/

int main(int argc, char *argv[]) {
  int init[] = {8, 6, 7, 2, 5, 4, 3, 0, 1};
  int go[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

  //int* initial = eish(init);
  //int* goal = eish(go);

  Node* startState = new Node(init, 7, 0);
  Node* goalState = new Node(go, 8, 0);

  //cout<<*(startState->getPuzzle()+2)<<initial[2]<<init[2]<<endl;
  Search* bfs = new Search(startState, goalState);

  cout<<"It took "<<bfs->breadthFS()<<" Number of iterations, with "<<goalState->getOptimum()<<" Optimum"<<endl;
  return 0;
}
