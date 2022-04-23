#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include "CustomDataStructure.h"
#include <iostream>

using namespace std;

class BreadthFirstSearch{
  private:
    CustomDataStructure open;
    CustomDataStructure closed;
    queue<Node*> kids;
    Node* startState;
    Node* goalState;

  public:
    BreadthFirstSearch(Node*, Node*);
    ~BreadthFirstSearch();
    int breadthFS();
};

#endif // SEARCH_H_
