#include "Node.h"
#include <iostream>
#include <math.h>

Node::Node(int* pz, int z, int o, Node* gal) : zero(z), optimum(o), goal(gal){
  puzzle = copyPu(pz);
  //  cout<<endl<<pz[1]<<endl;
  heuristic = 0;
}

Node::~Node(){
  delete[] puzzle;
}

int* Node::getPuzzle(){
  return puzzle;
}

int* Node::copyPu(int* p){
  int* cp = new int[9];
  for(int i = 0; i < 9; i++){
    cp[i] = p[i];
    //cout<<p[i];
  }
  return cp;
}

Node* Node::generateChildren(char w){
  int* cp = copyPu(puzzle);
  int nz = zero;
  if(w =='l'){
     if((zero == 2) || (zero == 5) || (zero == 8)) {
       return NULL;
     }else{
       *(cp+zero) = *(cp+zero+1);
       nz = zero+1;
       *(cp+nz) = 0;
     }
   }else if(w == 'r'){
      if((zero == 0) || (zero == 3) || (zero == 6)){
         return NULL;
      }else{
         *(cp+zero) = *(cp+zero-1);
         nz = zero-1;
         *(cp+nz) = 0;
      }
   }else if(w == 'u'){
      if((zero == 0) | (zero == 1) | (zero ==2)){
         return NULL;
      }else{
         *(cp+zero) = *(cp+zero-3);
         nz = zero - 3;
         *(cp+nz) = 0;
      }
   }else{
      if((zero == 6) | (zero == 7) | (zero == 8)){
         return NULL;
      }else{
         *(cp+zero) = *(cp+zero+3);
         nz = zero+3;
         *(cp+nz) = 0;
      }
  }
  Node* nc = new Node(cp, nz, optimum+1, goal);
  nc->setHeuristic(goal);
  //cout<<goal->store()<<endl;
  return nc;
}

void Node::setHeuristic(Node* cm){
  string data = store();
  string goal = cm->store();
  int sum=0;

    for (int i=0; i<data.length(); i++) {
        char dataChar=data[i];
        if (dataChar!='0') {
            int goalCoords=getCoords(goal, dataChar);
            sum+=(abs((i%3)-(goalCoords%3))+abs(floor(i/3)-floor(goalCoords/3)));
        }
    }

    heuristic = sum;
}

int Node::getHeuristic() const{
  return heuristic;
}

bool Node::equal(Node* cm){
  return (store() == cm->store());
}

int Node::getOptimum(){
  return optimum;
}

void Node::setOptimum(int n){
  optimum = n;
}

string Node::store() const{
  string ret = "";
  for(int i = 0; i < 9; i++){
    ret = ret+to_string(puzzle[i]);
  }
  return ret;
}

int Node::getCoords(string data, char x) {
        for (int i=0; i<data.length(); i++) {
            if (data[i]==x) return i;
        }
        return -1;
}

/*public Node* Node::rightShift(){
  int* cp = copyPu(puzzle);
  if((zero == 0) || (zero == 3) || (zero == 6)){
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero-1);
    zero--;
    *(cp+zero) = 0;
    return cp;
  }
}

public Node* Node::downShift(){
  int* cp = copyPu(puzzle);
  if((zero == 6) | (zero == 7) | (zero == 8)){
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero+3);
    zero=zero+3;
    *(cp+zero) = 0;
    return cp;
  }
}

public Node* Node::upShift(){
  int* cp = copyPu(puzzle);
  if((zero == 0) | (zero == 1) | (zero ==2)){
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero-3);
    zero = zero - 3;
    *(cp+zero) = 0;
    return cp;
  }
}*/
