#ifndef STOREHASH_H_
#define STOREHASH_H_

#include <functional>

class StoreHash {
  public:
     size_t operator()(const Node* node) const{
        return hash<string>()(node->store());
    }
};


#endif // STOREHASH_H_
