#ifndef NODE_H_
#define NODE_H_

class Node{
  private:
      int* puzzle;
      int zero;
      int optimum;

  public:
      Node(int*);
      ~Node();
      Node* copyPu(int*);
      int getOptimum();
      void setOptimum(int);
      Node* generateChildren(char);
      bool equal(Node*);
      int* getPuzzle();
      /*Node* rightShift();
      Node* upShift();
      Node* downShift();*/
};

#endif // NODE_H_
