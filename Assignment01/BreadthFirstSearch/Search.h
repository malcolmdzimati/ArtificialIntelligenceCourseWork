#ifndef SEARCH_H
#define SEARCH_H

#include "Node.h"
#include <queue>
#include <unordered_set>

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
    int bfs();
};

#endif // SEARCH_H_
