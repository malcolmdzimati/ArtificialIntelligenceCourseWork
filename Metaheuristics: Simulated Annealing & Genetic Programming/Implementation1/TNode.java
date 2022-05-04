class TNode extends Node{
    int value;

    TNode(Node parent, int value){
        super(parent);
        this.value = value;
    }

    public char getType(){
        return 't';
    }

    public int getInt(){
        return value;
    }

    public void setInt(int value){
        this.value = value;
    }
}
