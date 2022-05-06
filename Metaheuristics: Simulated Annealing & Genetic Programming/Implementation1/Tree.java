import java.util.Stack;
import java.util.Objects;

public class Tree implements Comparable<Tree>{
    Node root;
    int numTNodes;
    String sum = "";
    float fitness=0;
    double accuracy;
    private int[][] data;
    private int[] ans;
    private int maxNum=20;
    String possibleOp = "-*/+";                //Different Possible values of Nodes

    public Tree(int[][] data, int[] ans){
        int min = 0;
        int max = 3;
        int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        root = new NNode(null, possibleOp.charAt(rand_int));

        numTNodes = 0;
        generateTree(root);
        this.data = data;
        this.ans = ans;
    }

    public Tree(int[][] data, int[] ans, Tree tree, boolean mu){
        this.data = data;
        this.ans = ans;
        root = new NNode(null, tree.returnRoot().getOp());
        copyNode(tree.returnRoot().getLeftChild(), root, 'l');
        copyNode(tree.returnRoot().getRightChild(), root, 'r');

        if(mu){
            mutation();
        }
    }

    public void copyNode(Node og, Node parent, char pos){
        if(og==null){
            return;
        }
        Node copy= null;

        if(og.getType()=='t'){
            copy = new TNode(parent, og.getInt());
        }else{
            copy = new NNode(parent, og.getOp());
        }

        if(pos=='l'){
            parent.setLeftChild(copy);
        }else{
            parent.setRightChild(copy);
        }

        copyNode(og.getLeftChild(), copy, 'l');
        copyNode(og.getRightChild(), copy, 'r');
    }

    public Node returnRoot(){
        return root;
    }

    public double getAccuracy(){
        return accuracy/data.length;
    }

    public void generateTree(Node parent){
        if(numTNodes>maxNum-2){
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

        if(rand_int<=9){
            nodel = new TNode(parent, rand_int);
            parent.setLeftChild(nodel);
            numTNodes++;
        }else{
            nodel = new NNode(parent, possibleOp.charAt(rand_int-10));
            parent.setLeftChild(nodel);
        }

        rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        if(rand_int<=9){
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
        System.out.println(" Number of Terminal nodes: "+numTNodes+"\n PostFix: "+sum);
        System.out.print(" Infix: ");
        printTree(root);
        System.out.println("\n");
    }

    public void calculateFitness(){
        sum="";
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

    public void changeValue(Node node, int[] arr, int i){
        if(node == null){
            return;
        }

        changeValue(node.getLeftChild(), arr, i++);
        if(node.getType()=='t'){
            i=i%9;
            node.setInt(arr[i]);
        }

        changeValue(node.getRightChild(), arr, i++);
    }

    public void changeValues(int[] arr){
        int i = 0;
        changeValue(root, arr, i);
    }

    public Node swapNode(){
        int min = 1;
        int max = (numTNodes)/2;
        int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        Node node = root;
        char prev = 'n';

        for(int i=0; i < rand_int; i++){
            int ran = (int)Math.floor(Math.random()*(max-min+1)+min);
            if(ran%2==0){
                if(node.getRightChild() != null){
                    node=node.getRightChild();
                    prev = 'r';
                }else{
                    node=node.getParent();
                    if(prev == 'r'){
                        node=node.getLeftChild();
                    }else{
                        node=node.getRightChild();
                    }
                }
            }else{
                if(node.getLeftChild() != null){
                    node=node.getLeftChild();
                    prev = 'l';
                }else{
                    node=node.getParent();
                    if(prev == 'r'){
                        node=node.getLeftChild();
                    }else{
                        node=node.getRightChild();
                    }
                }
            }
        }

        return node;
    }

    public void countNTNodes(){
        numTNodes = 0;
        countN(root);
    }

    public void countN(Node n){
        if(n == null){
            return;
        }

        countN(n.getLeftChild());

        if(n.getType()=='t'){
            numTNodes++;
        }

        countN(n.getRightChild());
    }

    public void mutation(){
        Node node = swapNode();

        if(node.getType()=='t'){
            Node p = node.getParent();
            if(p.getLeftChild()==node){
                int min = 0;
                int max = 3;
                int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);
                node = new NNode(p, possibleOp.charAt(rand_int));
                p.setLeftChild(node);
            }else{
                int min = 0;
                int max = 3;
                int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);
                node = new NNode(p, possibleOp.charAt(rand_int));
                p.setRightChild(node);
            }
        }

        node.setLeftChild(null);
        node.setRightChild(null);

        countNTNodes();
        generateTree(node);
        countNTNodes();

        if(numTNodes>maxNum){
            mutation();
        }
    }

    @Override
    public boolean equals(Object o){
        if(this == o){
            return true;
        }

        if(o == null || getClass() != o.getClass()){
            return false;
        }

        Tree tree = (Tree) o;

        return Double.compare(tree.getAccuracy(), accuracy) == 0;
    }

    @Override
    public int hashCode(){
        return Objects.hash(sum, accuracy);
    }

    @Override
    public int compareTo(Tree tree){
        if(getAccuracy() < tree.getAccuracy()){
            return 1;
        }else if(getAccuracy() > tree.getAccuracy()){
            return -1;
        }else{
            return 0;
        }
    }

    public void evaluate(){
        accuracy = 0;
        for(int i=0; i<data.length; i++){
            int decision=-1;
            changeValue(root, data[i], 0);
            calculateFitness();
            if(fitness>=0.5){
                decision = 1;
            }else{
                decision = 0;
            }

            if(decision==ans[i]){
                accuracy++;
            }
        }
    }
}
