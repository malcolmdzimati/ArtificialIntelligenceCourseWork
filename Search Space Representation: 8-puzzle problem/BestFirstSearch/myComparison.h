#ifndef MYCOMPARISON_H_
#define MYCOMPARISON_H_

#include <functional>

class myComparison : binary_function<Node*, Node*, bool>{
  public:
     bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->getHeuristic() > rhs->getHeuristic();
    }
};

#endif // MYCOMPARISON_H_
