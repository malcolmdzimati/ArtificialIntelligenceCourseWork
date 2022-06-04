import java.util.ArrayList;

public class Layer{
    private ArrayList<Neuron> layer = new ArrayList<>();
    private int layers;


    public Layer(int nlayers, ArrayList<Double> prevLayerOutputs){
        layers = nlayers;


        for(int i =0; i<layers; i++){
            layer.add(new Neuron(prevLayerOutputs));
        }

    }

    public ArrayList<Double> results(){
        ArrayList<Double> outputs = new ArrayList<>();

        for(Neuron neurons : layer){
            outputs.add(neurons.feedFoward());
        }

        return outputs;
    }
}
