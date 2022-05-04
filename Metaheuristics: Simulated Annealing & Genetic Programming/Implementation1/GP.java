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
            generation[i].showTree();
        }
    }

    public void calculateFitness(){

    }
}
