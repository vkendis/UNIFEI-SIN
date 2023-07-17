import java.util.Scanner; //Importar scanner para leitura do usuario

public class NomeAlunos {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in); //Leitura
        String nome1 = teclado.next();            //Leitura nome 1  
        String nome2 = teclado.next();            //Leitura nome 2 
        String nome3 = teclado.next();            //Leitura nome 3 
        System.out.println("*****Print dos nomes separados por espaco*****");
        System.out.println(nome1 + ' ' + nome2 + ' ' + nome3); // Print dos nomes separados por espaco
        System.out.println("\n");
        System.out.println("*****Print dos nomes com quebra de linha*****");
        System.out.println(nome1 + "\n" + nome2 + "\n" + nome3);
    }
}
