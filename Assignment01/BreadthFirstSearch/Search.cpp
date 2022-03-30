#include "Search.h"
#include "Node.h"
#include <queue>

Search::Search(Node* ss, Node* gs) : startState(ss), goalState(gs){

}

Search::~Search(){
  delete startState;
  delete goalState;
}

int Search::bds(){
  queue<Node*> open;
  queue<Node*> closed;
  boolean failure = true;
  int iterations = 0;
  int optimum = 0;

  open.push(startState);

  while(!open.empty() && failure){
    iterations++;
    Node* current = open.pop();

    if(current.equal(goalState)){
      goalState.setOptimum(current.getOptimum());
      return iterations;
    }else{

    }
  }
}
