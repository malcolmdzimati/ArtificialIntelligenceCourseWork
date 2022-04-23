#ifndef CUSTOMDATASTRUCTURE_H
#define CUSTOMDATASTRUCTURE_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include <iostream>
#include "NodeEqual.h"
#include "StoreHash.h"

using namespace std;

class CustomDataStructure{
    private:
        queue<Node*> que;
        unordered_set<Node*, StoreHash, NodeEqual> has;

    public:
        CustomDataStructure();
        void push(Node*);
        Node* pop();
        bool contains(Node*);
        bool empty();
        void checkSwap(Node*);
};

#endif // CUSTOMDATASTRUCTURE_H