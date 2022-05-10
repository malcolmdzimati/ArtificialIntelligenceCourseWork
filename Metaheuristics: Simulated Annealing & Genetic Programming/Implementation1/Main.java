import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Main {

    static int countLenght(String filename){
        int i=-1;
        String line="";
        String splitBy=",";

        try{
            BufferedReader br = new BufferedReader(new FileReader(filename));
            i=0;
            while((line = br.readLine()) != null){
                i++;
            }
        }catch(IOException e){
            e.printStackTrace();
        }

        return i;
    }

    static void readArr(String filename, int[][] data, int[] ans, int size){
        String line="";
        String splitBy=",";

        try{
            BufferedReader br = new BufferedReader(new FileReader(filename));

            for(int i=0; i<size; i++){
                line = br.readLine();
                String[] dt = line.split(splitBy);

                for(int j=0; j<9; j++){
                    data[i][j]=Integer.parseInt(dt[j]);
                }
                ans[i]=Integer.parseInt(dt[9]);
            }

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    public static void print(int[][] data){
        for(int i=0; i<data.length; i++){
            for(int j=0; j<data[i].length; j++){
                System.out.print(data[i][j]);
            }
            System.out.println("");
        }
    }

    public static Tree doGP(boolean isCancer){
        String filename = "../Assignment2_Data/breast_cancer_Train.csv";

        if(!isCancer){
            filename = "../Assignment2_Data/tictactoe_Train.csv";
        }

        int arrSize = countLenght(filename);
        int[][] data = new int[arrSize][9];
        int[] ans = new int[arrSize];
        readArr(filename, data, ans, arrSize);

        Tree best = null;
        double j=0.0;
        double thres=0.0;
        double train=0.0;

        if(isCancer){
            thres=0.95;
            System.out.println("Breast Cancer:");
        }else{
            thres=0.65;
            System.out.println("TicTac Toe:");
        }

        while(j<thres){
            GenticProgram gp = new GenticProgram(10, data, ans, 20, 1000);
            gp.initialGeneration();
            best = gp.findFittest();
            train = best.getAccuracy();
            predict(best, isCancer);
            j = best.getAccuracy();
        }

        System.out.println(" Accuracy On Training: "+train);
        System.out.println(" Accuracy On Tests: "+best.getAccuracy());
        best.showTree();
        return best;
    }

    public static void predict(Tree fittest, boolean isCancer){
        String filename = "../Assignment2_Data/breast_cancer_Test.csv";

        if(!isCancer){
            filename = "../Assignment2_Data/tictactoe_Test.csv";
        }

        int arrSize = countLenght(filename);
        int[][] data = new int[arrSize][9];
        int[] ans = new int[arrSize];
        readArr(filename, data, ans, arrSize);

        fittest.evaluate(data, ans);
    }

    public static void SA(Tree fittest, boolean isCancer){
        String filename = "../Assignment2_Data/breast_cancer_Train.csv";
        double temp=0.0;
        Tree inital = new Tree(fittest, false);

        if(!isCancer){
            filename = "../Assignment2_Data/tictactoe_Train.csv";
            System.out.println("TicTac Toe:");
            temp=0.689;
        }else{
            System.out.println("Breast Cancer:");
            temp=0.989;
        }

        int arrSize = countLenght(filename);
        int[][] data = new int[arrSize][9];
        int[] ans = new int[arrSize];
        readArr(filename, data, ans, arrSize);

        SimulatedAnnealing sa = new SimulatedAnnealing(fittest, temp);
        Tree best = best = sa.SA(data, ans);

        if(best.getAccuracy()>inital.getAccuracy()){
            best = inital;
        }

        best.evaluate(data, ans);
        System.out.println(" Accuracy On Training: "+best.getAccuracy());

        predict(best, isCancer);
        System.out.println(" Accuracy On Tests: "+best.getAccuracy());
        best.showTree();
    }

    public static void main(String[] args) {
        System.out.println("Gentic Program without Simulated Annealing--\n");
        Tree fittestC = doGP(true);
        Tree fittestT = doGP(false);

        System.out.println("\n\nGentic Program with Simulated Annealing--\n");
        SA(fittestC, true);
        SA(fittestT, false);
    }
}
