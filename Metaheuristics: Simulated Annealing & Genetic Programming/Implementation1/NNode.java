class NNode extends Node{
    char operation;

    NNode(Node parent, char operation){
        super(parent);
        this.operation = operation;
    }

    public char getType(){
        return 'n';
    }

    public char getOp(){
        return operation;
    }
}
