import java.util.Stack;

public class Tree {
    Node root;
    int numTNodes;
    String sum = "";
    float fitness;
    String possibleOp = "-*/+";                //Different Possible values of Nodes

    public Tree(){
        int min = 0;
        int max = 3;
        int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        root = new NNode(null, possibleOp.charAt(rand_int));

        numTNodes = 0;
        generateTree(root);
    }

    public void generateTree(Node parent){
        if(numTNodes>7){
            int min = 1;
            int max = 10;
            Node nodel;
            Node noder;

            int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

            nodel = new TNode(parent, rand_int);
            parent.setLeftChild(nodel);

            rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

            noder = new TNode(parent, rand_int);
            parent.setRightChild(noder);

            numTNodes += 2;
        }

        int min = 1;
        int max = 13;
        Node nodel;
        Node noder;

        int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        if(rand_int<=10){
            nodel = new TNode(parent, rand_int);
            parent.setLeftChild(nodel);
            numTNodes++;
        }else{
            nodel = new NNode(parent, possibleOp.charAt(rand_int-10));
            parent.setLeftChild(nodel);
        }

        rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        if(rand_int<=10){
            noder = new TNode(parent, rand_int);
            parent.setRightChild(noder);
            numTNodes++;
        }else{
            noder = new NNode(parent, possibleOp.charAt(rand_int-10));
            parent.setRightChild(noder);
        }

        if(nodel.getType() == 'n'){
            generateTree(nodel);
        }

        if(noder.getType() == 'n'){
            generateTree(noder);
        }
    }

    public void printTree(Node node){
        if(node == null){
            return;
        }

        printTree(node.getLeftChild());

        if(node.getType()!='t'){
            System.out.print(node.getOp()+" ");
        }else{
            System.out.print(node.getInt()+" ");
        }

        printTree(node.getRightChild());

    }

    public void findPostfix(Node node){
        if(node == null){
            return;
        }

        findPostfix(node.getLeftChild());

        findPostfix(node.getRightChild());

        if(node.getType()!='t'){
            sum+=node.getOp();
        }else{
            if(node.getInt()==10){
                sum+='0';
            } else{
                sum+=node.getInt();
            }
        }
    }

    public int getNTNodes(){
        return numTNodes;
    }

    public void showTree(){
        calculateFitness();
        System.out.print("Number of terminal nodes: "+numTNodes+"PostFix: "+sum+" Fitness: "+fitness+"\n");
        printTree(root);
        System.out.println(" ");
    }

    public void calculateFitness(){
        findPostfix(root);

        Stack<Float> stack = new Stack<>();

        for(int i=0; i<sum.length(); i++){
            char c=sum.charAt(i);

            if(Character.isDigit(c)){
                if(c=='0'){
                    int j =10;
                    float m = j;
                    stack.push(m);
                }else{
                    int j =c-'0';
                    float m = j;
                    stack.push(m);
                }
            }else{
                float num1 = stack.pop();
                float num2 = stack.pop();

                switch(c){
                    case '*':
                        stack.push(num2*num1);
                        break;

                    case '/':
                        stack.push(num2/num1);
                        break;

                    case '+':
                        stack.push(num2+num1);
                        break;

                    case '-':{
                        stack.push(num2-num1);
                    }
                }
            }
        }
        fitness = stack.pop();

    }
}
