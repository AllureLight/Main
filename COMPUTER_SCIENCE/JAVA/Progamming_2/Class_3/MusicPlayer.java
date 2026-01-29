package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_3;

public class MusicPlayer {
    private SoundBox boxs;
    private Display display;

    public MusicPlayer() {
        boxs = new SoundBox();
        display = new Display();
    }

    public void play(Music m) {
        display.displayData(m.getName());
        boxs.makeSound(m.getLyrics());
    }
}
