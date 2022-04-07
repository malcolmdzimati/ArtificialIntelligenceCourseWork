#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

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

class HillClimbing{
  private:
    CustomDataStructure open;
    CustomDataStructure closed;
    priority_queue<Node*, vector<Node*>, myComparison> kids;
    Node* startState;
    Node* goalState;

  public:
    HillClimbing(Node*, Node*);
    ~HillClimbing();
    int hillClimbing();
};

#endif // HILLCLIMBING_H
