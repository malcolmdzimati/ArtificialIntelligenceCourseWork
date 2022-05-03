public class Tree {
    private String state;
    //int maxDepth;
    private String possibleNodes = "-*/+0123456789";                //Different Possible values of Nodes

    public Tree(){
        state = "";
        //maxDepth = maxdepth;
    }

    public void generateTree(){
        int min = 0;
        int max = 3;
        int rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

        state += possibleNodes.charAt(rand_int);
        max=13;

        for(int i=0; i<9; i++){
            rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);

            for(int j=0; j<4; j++){
                state+=possibleNodes.charAt(rand_int);
                if(rand_int<4){
                    break;
                }
                rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);
            }

            if(rand_int>3){
                min=4;
                rand_int = (int)Math.floor(Math.random()*(max-min+1)+min);
                state+=possibleNodes.charAt(rand_int);
            }
        }
    }

    public void printTree(){
        System.out.println(state);
    }
}
