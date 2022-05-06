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

    public static void main(String[] args) {
        String filename = "../Assignment2_Data/breast_cancer_Train.csv";
        int arrSize = countLenght(filename);
        int[][] data = new int[arrSize][9];
        int[] ans = new int[arrSize];
        readArr(filename, data, ans, arrSize);

        GP gn = new GP(10, data, ans);
        gn.initialGeneration();
        Tree best = gn.findFittest(5000);
        System.out.println("Accuracy: "+best.getAccuracy());
        best.showTree();
    }
}
