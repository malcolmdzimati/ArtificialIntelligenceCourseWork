#include "BreadthFirstSearch.h"

using namespace std;

BreadthFirstSearch::BreadthFirstSearch(Node* ss, Node* gs) : startState(ss), goalState(gs){
 // cout<<startState->store()<<endl;
}

BreadthFirstSearch::~BreadthFirstSearch(){
  delete startState;
  delete goalState;
}

int BreadthFirstSearch::breadthFS(){
  int iterations = 0;

  open.push(startState);
  //cout<<open.front()->store()<<endl;

  while(!open.empty()){
    iterations++;
    Node* current = open.pop();

    if(current->equal(goalState)){
      //cout<<current->store()<<endl<<goalState->store()<<endl;
      goalState->setOptimum(current->getOptimum());
      return iterations;
    }
    closed.push(current);

    Node* lChild = current->generateChildren('l');
    Node* rChild = current->generateChildren('r');
    Node* uChild = current->generateChildren('u');
    Node* dChild = current->generateChildren('d');

    if(lChild != NULL){
      kids.push(lChild);
    }

    if(rChild != NULL){
      kids.push(rChild);
    }

    if(uChild != NULL){
      kids.push(uChild);
    }

    if(dChild != NULL){
      kids.push(dChild);
    }

    for(int i = 0; i < kids.size(); i++){
      Node* child = kids.front();
      kids.pop();
      if(!closed.contains(child) && !open.contains(child)){
        open.push(child);
      }else if(open.contains(child)){
        open.checkSwap(child);
      }
    }

   }
  return -1;
}
