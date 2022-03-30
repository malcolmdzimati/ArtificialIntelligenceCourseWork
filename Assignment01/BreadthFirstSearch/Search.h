#ifndef SEARCH_H_
#define SEARCH_H_

#include "Node.h"
#include <queue>
#include <unordered_set>

using namespace std;

class Search{
  private:
    queue<Node*> open;
    unordered_set<tring> closed;
    Node* startState;
    Node* goalState;

  public:
    Search(Node*, Node*);
    ~Search();
    int bfs();
};

#endif // SEARCH_H_
