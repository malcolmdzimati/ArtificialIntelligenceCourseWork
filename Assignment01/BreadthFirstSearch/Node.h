#ifndef NODE_H_
#define NODE_H_

class Node{
  private:
      int* puzzle;
      int zero;

  public:
      Node(int*);
      ~Node();
      Node* copyPu(int*);
      Node* generateChildren(char);
      /*Node* rightShift();
      Node* upShift();
      Node* downShift();*/
};

#endif // NODE_H_
