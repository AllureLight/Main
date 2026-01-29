package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_3;

public class PlayerTest {
    public static void main(String[] args) {
        Music mysong = new Music("Test", "testing testing");
        MusicPlayer myplayer = new MusicPlayer();
        myplayer.play(mysong);
    }
}
