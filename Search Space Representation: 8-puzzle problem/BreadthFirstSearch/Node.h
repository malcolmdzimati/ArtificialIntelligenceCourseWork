#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <math.h>

using namespace std;

class Node{
  private:
      int* puzzle;
      int zero;
      int optimum;

  public:
      Node(int*, int, int);
      ~Node();
      int* copyPu(int*);
      string store() const;
      int getOptimum();
      void setOptimum(int);
      Node* generateChildren(char);
      bool equal(Node*);
      int* getPuzzle();
      //bool operator<(const Node* n1, const Node* n2);
      /*Node* rightShift();
      Node* upShift();
      Node* downShift();*/
};

#endif // NODE_H_
