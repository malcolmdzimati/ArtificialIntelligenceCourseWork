
import java.util.PriorityQueue;

public class GenticProgram{
    private Tree generation[];                                            //Current generation
    private PriorityQueue<Tree> sortedGeneration;                         //Maximum Length of Tree
    private int popSize;                                                  //Population Size of each generation
    private int[][] data;
    private int[] ans;
    private int maxT;
    private int numGen;


    public GenticProgram(int popsize, int[][] data, int[] ans, int maxT, int numGen){
        generation = new Tree[popsize];
        popSize = popsize;
        sortedGeneration = new PriorityQueue<>();
        //maxDepth = maxdepth;
        this.data = data;
        this.ans = ans;
        this.maxT = maxT;
        this.numGen = numGen;
    }

    public void initialGeneration(){
        for(int i = 0; i < popSize; i++){
            generation[i] = new Tree(maxT);
            while(generation[i].getNTNodes()>20 || generation[i].getNTNodes()<4){
                generation[i] = new Tree(maxT);
            }
        }
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

        while(n2.getType()=='t'){
            n2=t2.swapNode();
        }

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

    public Tree findFittest(){
        for(Tree person : generation){
                person.evaluate(data, ans);
                sortedGeneration.add(person);
        }

        for(int i=0; i<numGen; i++){

            generation = new Tree[popSize];

            for(int j=0; j<popSize;){
                Tree t1 = sortedGeneration.remove();

                if(t1.getAccuracy()>0.95){
                    return t1;
                }

                Tree t2 = sortedGeneration.remove();

                if(j<popSize){
                    generation[j++] = new Tree(t1, true);
                }

                if(j<popSize){
                    generation[j++] = new Tree(t2, true);
                }

                crossOver(t1, t2);

                if(j<popSize){
                    generation[j++] = t1;
                }

                if(j<popSize){
                    generation[j++] = t2;
                }
            }

            sortedGeneration = new PriorityQueue<>();

            for(Tree person : generation){
                person.evaluate(data, ans);
                sortedGeneration.add(person);
                if(person.getAccuracy()==1){
                    return person;
                }
            }
        }
        return sortedGeneration.remove();
    }
}
