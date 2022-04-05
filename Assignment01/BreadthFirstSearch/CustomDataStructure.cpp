#include "CustomDataStructure.h"

CustomDataStructure::CustomDataStructure(){}

void CustomDataStructure::push(Node* nn){
    que.push(nn);
    has.insert(nn);
}

Node* CustomDataStructure::pop(){
    Node* ret = que.front();
    que.pop();
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
        has.erase(nn);
        has.insert(nn);
        while(!que.empty()){
            Node* ret = que.front();
            que.pop();

            if(ret->store() != nn->store()){
                que_cpy.push(ret); 
            }else{
                que_cpy.push(nn);
            }
        }

        while (!que_cpy.empty())
        {
            Node* ret = que_cpy.front();
            que_cpy.pop();
            que.push(ret);
        }
        
    }
}

