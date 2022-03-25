#ifndef NODE_H_
#define NODE_H_

class Node{
  private:
      int puzzle[9];
      int zero;

  public:
      Node(int[9]);
      Node* leftShift();
      Node* rightShift();
      Node* upShift();
      Node* downShift();
};

#endif // NODE_H_
