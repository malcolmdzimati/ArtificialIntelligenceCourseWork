#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include "myComparison.h"
#include "NodeEqual.h"
#include "StoreHash.h"

using namespace std;

class Search{
  private:
    queue<Node*> open;
    priority_queue<Node*, vector<Node*>, myComparison> kids;
    unordered_set<Node*, StoreHash, NodeEqual> closed;
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
