import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        File file = new File("balance-scale.data");
        try{
            Scanner sc = new Scanner(file);

            ArrayList<ArrayList<Double>> data = new ArrayList<ArrayList<Double>>();
            ArrayList<Integer> result = new ArrayList<>();

            for(int i=0; i<625; i++){
                String[] line = sc.nextLine().split(",");
                if(line[0].equals("L")){
                    result.add(0);
                }else if(line[0].equals("R")){
                    result.add(1);
                }else {
                    result.add(2);
                }

                ArrayList<Double> temp = new ArrayList<>();
                temp.add(Double.parseDouble(line[1]));
                temp.add(Double.parseDouble(line[2]));
                temp.add(Double.parseDouble(line[3]));
                temp.add(Double.parseDouble(line[4]));

                data.add(temp);
            }

            System.out.println(data.get(20));
            Layer h1 = new Layer(6, data.get(20));
            System.out.println();
            Layer h2 = new Layer(6, h1.results());
            System.out.println();
            Layer h3 = new Layer(6, h2.results());
            System.out.println();
            Layer h4 = new Layer(6, h3.results());
            System.out.println();
            Layer finl = new Layer(3, h4.results());
            System.out.println();
            Neuron output = new Neuron(finl.results());
            double t = output.softmax(0, finl.results());
            double tt = output.softmax(1, finl.results());
            double ttt = output.softmax(2, finl.results());

            System.out.println(result.get(20)+" "+t+" "+tt+" "+ttt);
        }catch (Exception e){

        }
    }
}
