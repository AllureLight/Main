package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_0;

public class Relogio {
    //variaveis de instancia
    int hora, minuto, segundo;

    public void exibirHorario(){
        System.out.println(hora + ":" + minuto + ":" + segundo);
    }

    public int somaMinutosSegundos(){
        return (minuto * 60) + segundo;
    }
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
