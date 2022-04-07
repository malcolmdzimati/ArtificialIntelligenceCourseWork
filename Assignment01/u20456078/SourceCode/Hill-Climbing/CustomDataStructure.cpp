#include "CustomDataStructure.h"

CustomDataStructure::CustomDataStructure(){}

void CustomDataStructure::push(Node* nn){
    que.push_front(nn);
    has.insert(nn);
}

Node* CustomDataStructure::pop(){
    Node* ret = que.front();
    que.pop_front();
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

void CustomDataStructure::remove(Node* nn){
    auto inq = has.find(nn);
    queue<Node*> que_cpy;

    if((*inq)->getOptimum() > nn->getOptimum()){
        has.erase(nn);
        while(!que.empty()){
            Node* ret = que.front();
            que.pop_front();

            if(ret->store() != nn->store()){
                que_cpy.push(ret); 
            }
        }

        while (!que_cpy.empty())
        {
            Node* ret = que_cpy.front();
            que_cpy.pop();
            que.push_front(ret);
        }
    }
}

void CustomDataStructure::pushKids(deque<Node*>* kids){

    while(!kids->empty()){
        Node* child = kids->front();
        que.push_front(child);
        kids->pop_front();
        has.insert(child);
    }
}


