package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_3;

public class Music {
    private String name;
    private String lyrics;

    public Music(String name, String lyrics) {
        this.name = name;
        this.lyrics = lyrics;
    }

    public String getLyrics(){
        return lyrics;
    }

    public String getName(){
        return name;
    }
}
