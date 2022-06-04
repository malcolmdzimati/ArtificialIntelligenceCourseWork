import java.io.*;
import java.util.*;

public class Neuron {
    private ArrayList<Double> weights = new ArrayList<>();
    private ArrayList<Double> input = new ArrayList<>();
    Random rd = new Random();
    private double output;
    private double bias;

    public Neuron(ArrayList<Double> input){
        this.input = input;
        for(int i =0; i<input.size(); i++){
            weights.add(rd.nextDouble());
        }
        bias = rd.nextDouble()*10;
        output = bias;
    }

    public void linearOperation(){
        for(int i = 0; i<input.size(); i++){
            output+=input.get(i)*weights.get(i);
        }
    }

    public void nonLinearOperation(){
        output = sigmoid(output);
    }

    public double sigmoid(double x) {
        return (1/( 1 + Math.pow(Math.E,(-1*x))));
    }

    public double softmax(double input, ArrayList<Double> values) {
        double[] neuronValues = new double[values.size()];

        int i=0;
        for(double x : values){
            neuronValues[i] = x;
            i++;
        }

        double total = Arrays.stream(neuronValues).map(Math::exp).sum();
        return Math.exp(input) / total;
    }

    public double feedFoward(){
        linearOperation();
        nonLinearOperation();
        System.out.println("Weights: "+weights+", bias: "+bias);
        return output;
    }
}
