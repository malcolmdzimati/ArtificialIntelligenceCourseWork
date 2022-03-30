#include "Search.h"

using namespace std;
Search::Search(Node* ss, Node* gs) : startState(ss), goalState(gs){

}

Search::~Search(){
  delete startState;
  delete goalState;
}



int Search::bfs(){
  int iterations = 0;
  int optimum = 0;

  open.push(startState);

  while(!open.empty()){
    iterations++;
    Node* current = open.pop();

    if(current.equal(goalState)){
      goalState.setOptimum(current.getOptimum());
      return iterations;
    }
    closed.insert(current.store());

    Node* lChild = current.generateChildren('l');
    Node* rChild = current.generateChildren('r');
    Node* uChild = current.generateChildren('u');
    Node* dChild = current.generateChildren('d');

    if(lChild != NULL){
      auto it = closed.find(lChild.store());
      if(it != closed.end){
        open.push(lChild);
      }
    }

   if(rChild != NULL){
      auto it = closed.find(rChild.store());
      if(it != closed.end){
        open.push(rChild);
      }
    }

   if(uChild != NULL){
      auto it = closed.find(uChild.store());
      if(it != closed.end){
        open.push(uChild);
      }
    }

   if(dChild != NULL){
      auto it = closed.find(dChild.store());
      if(it != closed.end){
        open.push(dChild);
      }
    }

   return 0;
   }
}
