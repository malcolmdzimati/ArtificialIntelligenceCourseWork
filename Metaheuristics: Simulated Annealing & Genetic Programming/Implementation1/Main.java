import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) {

        GP gn = new GP(100);
        gn.initialGeneration();
    }

    public int countLenght(String filename){
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

    public void readArr(String filename, int[][] data, int[] ans, int size){
        String line="";
        String splitBy=",";

        try{
            BufferedReader br = new BufferedReader(new FileReader(filename));

            for(int i=0; i<size; i++){
                line = br.readLine();
                String[] dt = line.split(splitBy);
                for(int j=0; j<9; i++){
                    data[i][j]=Integer.parseInt(dt[j]);
                }
                ans[i]=Integer.parseInt(dt[9]);
            }

        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
