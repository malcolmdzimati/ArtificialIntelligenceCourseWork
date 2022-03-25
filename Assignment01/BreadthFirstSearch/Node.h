#ifndef NODE_H_
#define NODE_H_

class Node{
  private:
      int* puzzle;
      int zero;

  public:
      Node(int*);
      Node* leftShift();
      Node* rightShift();
      Node* upShift();
      Node* downShift();
};

#endif // NODE_H_
