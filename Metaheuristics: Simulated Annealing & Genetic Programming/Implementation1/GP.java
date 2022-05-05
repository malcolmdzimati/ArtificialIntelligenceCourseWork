public class GP{
    private Tree generation[];                                          //Current generation
    //private int maxDepth;                                               //Maximum Length of Tree
    private int popSize;                                                //Population Size of each generation

    public GP(int popsize){
        generation = new Tree[popsize];
        popSize = popsize;
        //maxDepth = maxdepth;
    }

    public void initialGeneration(){
        for(int i = 0; i < popSize; i++){
            generation[i] = new Tree();
            while(generation[i].getNTNodes()>9 || generation[i].getNTNodes()<4){
                generation[i] = new Tree();
            }
            //generation[i].showTree();
        }

        generation[0].showTree();
        generation[0].mutation();
        generation[0].showTree();
    }

    public void crossOver(Tree t1, Tree t2){
        Node n1 = t1.swapNode();
        Node n2 = t2.swapNode();
        while(n1.getParent()==null || n2.getParent()==null){
            n1 = t1.swapNode();
            n2 = t2.swapNode();
        }

        while(n1.getType()=='t'){
            n1=t1.swapNode();
        }


        /*System.out.print("Subtree 1: ");
        t1.printTree(n1);
        System.out.println("");*/

        while(n2.getType()=='t'){
            n2=t2.swapNode();
        }

        /*System.out.print("Subtree 2: ");
        t1.printTree(n2);
        System.out.println("");*/

        Node n11 = n1.getParent();
        Node n22 = n2.getParent();

        if(n11.getRightChild()==n1){
            n11.setRightChild(n2);
        }else{
            n11.setLeftChild(n2);
        }

        if(n22.getRightChild()==n2){
            n22.setRightChild(n1);
        }else{
            n22.setLeftChild(n1);
        }
    }
}
