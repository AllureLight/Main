package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_6;

public class Dracula extends Monster {
    
    @Override
    public void scare() {
        System.out.println("Dracula says: I want to suck your blood!");
    }

    public void scare(int n) {
        for(int i = 0; i < n; i++) {
            System.out.println("Dracula is frightening you!");
        }
    }
}
