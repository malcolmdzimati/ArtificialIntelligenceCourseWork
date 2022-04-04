#ifndef NODEEQUAL_H_
#define NODEEQUAL_H_

//#include <functional>

class NodeEqual {
  public:
     bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->store() == rhs->store();
    }
};

#endif // NODEEQUAL_H_
