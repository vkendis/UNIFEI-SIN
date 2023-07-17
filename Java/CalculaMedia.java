import java.util.Scanner; //Importar scanner para leitura do usuario

public class CalculaMedia 
{
    public static void main (String [] args)
    {
        Scanner teclado = new Scanner(System.in); 
        System.out.println("Digite a n1: ");
        float n1 = teclado.nextFloat();
        System.out.println("Digite a n2: ");
        float n2 = teclado.nextFloat();
        float media = (n1+n2)/2;
        System.out.println("Sua media sera igual a: " + media);
        if(media>=6)
        {
            System.out.println("Parabens");
        }else
            {
                System.out.println("Reprovado");
            }
    }
}
