class Node{
    Node leftChild;
    Node rightChild;
    Node parent;

    Node(Node parent){
        this.parent = parent;
    }

    public void setParent(Node newParent){
        parent = newParent;
    }

    public Node getParent(){
        return parent;
    }

    public void setLeftChild(Node child){
        leftChild = child;
        if(child!=null){
            child.setParent(this);
        }
    }

    public void setRightChild(Node child){
        rightChild = child;
        if(child!=null){
            child.setParent(this);
        }
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

    public void setPos(char pos){

    }

    public char getPos(){
        return '1';
    }
}
