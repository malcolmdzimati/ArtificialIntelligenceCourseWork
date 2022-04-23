#ifndef CUSTOMDATASTRUCTURE_H
#define CUSTOMDATASTRUCTURE_H

#include "Node.h"
#include <queue>
#include <unordered_set>
#include <iostream>
#include "myComparison.h"
#include "NodeEqual.h"
#include "StoreHash.h"

using namespace std;

class CustomDataStructure{
    private:
        priority_queue<Node*, vector<Node*>, myComparison> que;
        unordered_set<Node*, StoreHash, NodeEqual> has;

    public:
        CustomDataStructure();
        void push(Node*);
        Node* pop();
        bool contains(Node*);
        bool empty();
        void checkSwap(Node*);
        void remove(Node*, CustomDataStructure*);
};

#endif // CUSTOMDATASTRUCTURE_H