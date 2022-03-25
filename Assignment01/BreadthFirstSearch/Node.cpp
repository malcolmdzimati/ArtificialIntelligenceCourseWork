#include "Node.h"

Node::Node(int* pz, int z) : zero(z){
  puzzle = new int[9];
  for(int i =0; i< 9; i++){
    *(puzzle+i) = *(pz+i);
  }
}

public Node::CopyPu(int* new){
  for(int i = 0; i < 9; i++){

  }
}

public Node* Node::leftShift(){
  int* cp =
  if((zero == 2) || (zero == 5) || (zero == 8)) {
    return NULL;
  }else if((zero == 1) || (zero == 4) || (zero == 7)){

  }else if((zero == 0) || (zero == 3) || (zero == 6)){

  }else{

  }
}

public Node* Node::rightShift(){
  if((zero == 0) || (zero == 3) || (zero == 6)){
    return NULL;
  }else if((zero == 2 ) || (zero == 5) || (zero == 8)){

  }else if((zero == 1) ||  (zero == 4) || (zero == 7)){

  }
}

public Node* Node::UpShift(){
  if((zero == 0 ) || (zero == 1) | (zero == 2)){

  }else if((zero == 3) | (zero == 4) | (zero == 5)){

  }else if((zero == 6) | (zero == 7) | (zero ==8)){
    return NULL;
  }else{

  }
}

public Node* Node::DownShift(){
  if((zero == 0) | (zero == 1) | (zero ==2)){
    return NULL;
  }else if((zero == 3) | (zero ==4) |  (zero == 5)){

  }else if((zero == 6) | (zero == 7) | (zero == 8)){

  }else{

  }
}
