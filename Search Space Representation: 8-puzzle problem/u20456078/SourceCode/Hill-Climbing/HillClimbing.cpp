#include "HillClimbing.h"

using namespace std;

HillClimbing::HillClimbing(Node* ss, Node* gs) : startState(ss), goalState(gs){
 // cout<<startState->store()<<endl;
}

HillClimbing::~HillClimbing(){
  delete startState;
  delete goalState;
}



int HillClimbing::hillClimbing(){
  int iterations = 0;

  open.push(startState);
  //cout<<open.front()->store()<<endl;

  while(!open.empty()){
    iterations++;
    Node* current = open.pop();

    //cout<<"heuristic: "<<current->getHeuristic()<<endl;

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

    deque<Node*> children;

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


    while(!kids.empty()){
      Node* child = kids.top();
      kids.pop();

      if(!closed.contains(child) && !open.contains(child)){
        children.push_front(child);
      }else if(open.contains(child)){
        open.checkSwap(child);
        children.push_front(child);
        /*{
          open.remove(child);
          children.push_front(child);
        }*/
      }else if(closed.contains(child)){
        //open.push(child);
        closed.remove(child);
        //children.push_front(child);
      }
    }

    open.pushKids(&children);

    if(iterations == 5000000){
      return 0;
    }
  }
  return -1;
}

