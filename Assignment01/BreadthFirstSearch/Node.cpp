#include "Node.h"

Node::Node(int* pz, int z, int o) : zero(z), optimum(o){
  puzzle = copyPu(pz);
}

Node::~Node(){
  delete[] puzzle;
}

int* Node::getPuzzle(){
  return puzzle;
}

public Node* Node::copyPu(int* p){
  int* cp = new int[9];
  for(int i = 0; i < 9; i++){
    *(cp+i) = *(p+i);
  }
  return cp;
}

public Node* Node::generateChildren(char w){
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
  Node* nc = new Node(cp, nz, optimum+1);
  return nc;
}

bool Node::equal(Node* cm){
  int* c = cm->getPuzzle();

  for(int i; i < 9; i++){
    if(*(c+1) != *(puzzle+1))
      return false;
  }
  return true;
}

int Node::getOptimum(){
  return optimum;
}

void Node::setOptimum(int n){
  optimum = n;
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
  }*/
}
