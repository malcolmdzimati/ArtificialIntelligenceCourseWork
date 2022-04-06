#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include "CustomDataStructure.h"
#include "myComparison.h"
#include "NodeEqual.h"
#include "StoreHash.h"

using namespace std;

/*struct NodeEqual{
    public:
     bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->store() == rhs->store();
    }
};

struct storeHash{
    public:
    size_t operator()(const Node* node) const{
        return hash<string>()(node->store());
    }
};*/

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
