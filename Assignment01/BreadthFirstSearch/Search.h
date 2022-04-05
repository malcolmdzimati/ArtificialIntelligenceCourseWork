#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include "CustomDataStructure.h"
#include <iostream>

using namespace std;

class Search{
  private:
    CustomDataStructure open;
    CustomDataStructure closed;
    queue<Node*> kids;
    Node* startState;
    Node* goalState;

  public:
    Search(Node*, Node*);
    ~Search();
    int breadthFS();
    int bestFS();
    int hillClimbing();
    int aStar();
};

#endif // SEARCH_H_
