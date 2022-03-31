#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Search{
  private:
    queue<Node*> open;
    unordered_set<string> closed;
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
