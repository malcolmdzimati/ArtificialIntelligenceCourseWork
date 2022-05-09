import java.lang.Math;
import java.util.Random;

public class SimulatedAnnealing{
    private double temp;
    private Tree best;
    Random random;

    public SimulatedAnnealing(Tree treeFromGP, double tempreture){
        temp = tempreture;
        best = treeFromGP;
        random = new Random();
    }

    public double calculateCost(Tree t1, Tree t2, int[][] data, int[] ans){
        t2.evaluate(data, ans);
        t1.evaluate(data, ans);

        return t1.getAccuracy()-t2.getAccuracy();
    }

    public boolean calculateProb(Tree t1, Tree t2, double T, int[][] data, int[] ans){
        double ecT = Math.exp(calculateCost(t1, t2, data, ans));
        //System.out.println(ecT/T);
        if(1>(ecT/T)){
            return true;
        }
        return false;
    }

    public Tree SA(int[][] data, int[] ans){
        Tree current = new Tree(best, false);
        double t = best.getAccuracy();

        for(int i=1; i<=10;i++){
            Tree next = new Tree(best, true);

            if(current.getAccuracy() < best.getAccuracy()){
                best = current;
            }else if(calculateProb(current, next, t, data, ans)){
                current = next;
            }

            t=temp/Math.log(i+1);
        }

        return best;
    }

}
