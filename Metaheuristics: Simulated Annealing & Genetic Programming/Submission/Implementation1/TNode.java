class TNode extends Node{
    int value;
    char pos;

    public TNode(Node parent, int value){
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

    public void setPos(char pos){
        this.pos=pos;
    }

    public char getPos(){
        return pos;
    }
}
