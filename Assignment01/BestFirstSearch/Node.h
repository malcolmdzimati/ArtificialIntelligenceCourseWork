#ifndef NODE_H_
#define NODE_H_

#include <string>

using namespace std;

class Node{
  private:
      int* puzzle;
      int zero;
      int optimum;
      int heuristic;

  public:
      Node(int*, int, int);
      ~Node();
      int* copyPu(int*);
      string store();
      int getOptimum();
      void setOptimum(int);
      Node* generateChildren(char);
      bool equal(Node*);
      int* getPuzzle();
      void setHeuristic(Node*);
      int getHeuristic();
      //bool operator<(const Node* n1, const Node* n2);
      /*Node* rightShift();
      Node* upShift();
      Node* downShift();*/
};

#endif // NODE_H_
