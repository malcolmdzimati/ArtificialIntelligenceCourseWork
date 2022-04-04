#include "Search.h"

using namespace std;

Search::Search(Node* ss, Node* gs) : startState(ss), goalState(gs){
 // cout<<startState->store()<<endl;
}

Search::~Search(){
  delete startState;
  delete goalState;
}



int Search::breadthFS(){
  int iterations = 0;

  open.push(startState);
  //cout<<open.front()->store()<<endl;

  while(!open.empty()){
    iterations++;
    Node* current = open.front();
    open.pop();

    //cout<<"heuristic: "<<current->getHeuristic()<<endl;

    if(current->equal(goalState)){
      //cout<<current->store()<<endl<<goalState->store()<<endl;
      goalState->setOptimum(current->getOptimum());
      return iterations;
    }

    closed.insert(current);

    Node* lChild = current->generateChildren('l');
    Node* rChild = current->generateChildren('r');
    Node* uChild = current->generateChildren('u');
    Node* dChild = current->generateChildren('d');

    if(lChild != NULL){
      auto it = closed.find(lChild);
      if(it == closed.end()){
        kids.push(lChild);
      }
    }

   if(rChild != NULL){
      auto it = closed.find(rChild);
      //cout<<"correct"<<endl;
      if(it == closed.end()){
        kids.push(rChild);
        //cout<<"problem"<<endl;
      }
    }

   if(uChild != NULL){
      auto it = closed.find(uChild);
      if(it == closed.end()){
        kids.push(uChild);
      }
    }

   if(dChild != NULL){
      auto it = closed.find(dChild);
      if(it == closed.end()){
        kids.push(dChild);
      }
    }

    while(!kids.empty()){
      Node* top = kids.top();
      open.push(top);
      kids.pop();
    }
   }
  return -1;
}

int Search::bestFS(){
  int iterations = 0;

  return -1;
}

int Search::hillClimbing(){
  int iterations = 0;

  return -1;
}

int Search::aStar(){
  int iterations = 0;

  return -1;
}
