#include "CustomDataStructure.h"

CustomDataStructure::CustomDataStructure(){}

void CustomDataStructure::push(Node* nn){
    que.push(nn);
    has.insert(nn);
}

Node* CustomDataStructure::pop(){
    Node* ret = que.front();
    que.pop();
    auto inq = has.find(ret);
    ret = (*inq);
    has.erase(ret);

    return ret;
}

bool CustomDataStructure::contains(Node* nn){
    auto it = has.find(nn);
    return !(it == has.end());
}

bool CustomDataStructure::empty(){
    return has.empty() && que.empty();
}

void CustomDataStructure::checkSwap(Node* nn){
    auto inq = has.find(nn);
    queue<Node*> que_cpy;

    if((*inq)->getOptimum() > nn->getOptimum()){
        (*inq)->setOptimum(nn->getOptimum());
    }
}




