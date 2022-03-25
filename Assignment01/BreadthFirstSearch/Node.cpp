#include "Node.h"

Node::Node(int* pz, int z) : zero(z){
  puzzle = copyPu(pz);
}

public Node* Node::copyPu(int* p){
  int* cp = new int[9];
  for(int i = 0; i < 9; i++){
    *(cp+i) = *(p+i);
  }
}

public Node* Node::leftShift(){
  int* cp = copyPu(puzzle);
  if((zero == 2) || (zero == 5) || (zero == 8)) {
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero+1);
    zero++;
    *(cp+zero) = 0;
  }
}

public Node* Node::rightShift(){
  int* cp = copyPu(puzzle);
  if((zero == 0) || (zero == 3) || (zero == 6)){
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero-1);
    zero--;
    *(cp+zero) = 0;
  }
}

public Node* Node::downShift(){
  if((zero == 6) | (zero == 7) | (zero == 8)){
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero+3);
    zero=zero+3;
    *(cp+zero) = 0;
  }
}

public Node* Node::upShift(){
  if((zero == 0) | (zero == 1) | (zero ==2)){
    return NULL;
  }else{
    *(cp+zero) = *(cp+zero-3);
    zero = zero - 3;
    *(cp+zero) = 0;
  }
}
