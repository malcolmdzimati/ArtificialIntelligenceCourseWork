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

    public static Tree doGP(String filename, boolean isCancer){
        int arrSize = countLenght(filename);
        int[][] data = new int[arrSize][9];
        int[] ans = new int[arrSize];
        readArr(filename, data, ans, arrSize);

        GP gn = new GP(10, data, ans);
        Tree best = null;
        double j=0.0;
        double thres=0.0;

        if(isCancer){
            thres=0.95;
        }else{
            thres=0.75;
        }

        while(j<thres){
            gn.initialGeneration();
            best = gn.findFittest(1000);
            j = best.getAccuracy();
        }
        System.out.println("Breast Cancer Trainning:\n Accuracy: "+best.getAccuracy());
        best.showTree();
        return best;
    }

    public static void main(String[] args) {
        String filename = "../Assignment2_Data/breast_cancer_Test.csv";
        Tree fittestC = doGP(filename, true);

        filename = "../Assignment2_Data/tictactoe_Test.csv";
        Tree fittestT = doGP(filename, false);
    }
}
