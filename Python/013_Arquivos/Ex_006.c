/*6) Crie uma estrutura representando um atleta. Esta estrutura deve conter o nome, esporte, idade e altura do
atleta. A seguir, leia os dados de 5 atletas e armazene em um arquivo binário.
*/
#include <stdio.h>

typedef struct {
    char nome[100];
    char esporte[100];
    int idade;
    float altura;
} Atleta;

int main()
{
    Atleta atletas[5];

    // Ler os dados dos atletas
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do atleta %d: ", i + 1);
        scanf("%s", atletas[i].nome);

        printf("Digite o esporte do atleta %d: ", i + 1);
        scanf("%s", atletas[i].esporte);

        printf("Digite a idade do atleta %d: ", i + 1);
        scanf("%d", &atletas[i].idade);

        printf("Digite a altura do atleta %d: ", i + 1);
        scanf("%f", &atletas[i].altura);
    }

    // Abrir o arquivo binário para escrita
    FILE *arquivo = fopen("atletas.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrever os dados dos atletas no arquivo binário
    fwrite(atletas, sizeof(Atleta), 5, arquivo);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Dados dos atletas armazenados com sucesso.\n");

    return 0;
}
