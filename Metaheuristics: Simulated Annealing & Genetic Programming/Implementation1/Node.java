class Node{
    Node leftChild;
    Node rightChild;
    Node parent;
    int depth;

    Node(Node parent){
        this.parent = parent;
    }

    public void setParent(Node newParent){
        parent = newParent;
    }

    public void setLeftChild(Node child){
        leftChild = child;
    }

    public void setRightChild(Node child){
        rightChild = child;
    }

     public Node getLeftChild(){
        return leftChild;
    }

    public Node getRightChild(){
        return rightChild;
    }

    public char getType(){
        return 'n';
    }

    public char getOp(){
        return 'n';
    }

    public int getInt(){
        return -1;
    }

    public void setInt(int i){

    }
}
