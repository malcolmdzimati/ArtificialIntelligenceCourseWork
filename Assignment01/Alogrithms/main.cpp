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
  int init[] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
  int go[] = {1, 3, 4, 8, 6, 2, 7, 0, 5};

  //int* initial = eish(init);
  //int* goal = eish(go);

  Node* startState = new Node(init, 4, 0);
  Node* goalState = new Node(go, 7, 0);

  //cout<<*(startState->getPuzzle()+2)<<initial[2]<<init[2]<<endl;
  Search* bfs = new Search(startState, goalState);

  cout<<"It took "<<bfs->bfs()<<" Number of iterations, with "<<goalState->getOptimum()<<" Optimum"<<endl;
  return 0;
}
