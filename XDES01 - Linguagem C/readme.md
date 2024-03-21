<h1>Lógica de Programação com C</h1>

<p>Este repositório é dedicado à disciplina de Lógica de Programação, com ênfase na linguagem C. O curso tem como objetivo ensinar lógica de programação de maneira orgânica e integral, evitando o uso de funções encapsuladas para que o entendimento do conteúdo seja mais completo e aprofundado. O foco é desenvolver habilidades fundamentais de programação, proporcionando uma base sólida para aprendizados futuros.</p>

<h2>Conteúdos</h2>

<h3>Variáveis e Entrada de Dados</h3>
<p><strong>Exemplo:</strong> Definindo uma variável e lendo dados do usuário.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

int main() {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Você tem %d anos.", idade);
    return 0;
}
</code>
</pre>

<h3>Estruturas de Controle Condicionais</h3>
<p><strong>Exemplo:</strong> Usando if-else para verificar maioridade.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

int main() {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if(idade >= 18) {
        printf("Você é maior de idade.");
    } else {
        printf("Você é menor de idade.");
    }
    return 0;
}
</code>
</pre>

<h3>Estruturas de Controle Iterativas</h3>
<p><strong>Exemplo:</strong> Loop com for para imprimir números de 1 a 10.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

int main() {
    for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    return 0;
}
</code>
</pre>

<h3>Vetores</h3>
<p><strong>Exemplo:</strong> Definindo e utilizando um vetor para armazenar notas de alunos.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

int main() {
    float notas[5] = {7.5, 8.0, 9.5, 5.5, 8.5};
    for(int i = 0; i < 5; i++) {
        printf("Nota do aluno %d: %.2f\n", i+1, notas[i]);
    }
    return 0;
}
</code>
</pre>

<h3>Matrizes</h3>
<p><strong>Exemplo:</strong> Manipulação de uma matriz mxn.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

  int main() {
    int matriz[3][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
</code>
</pre>

<h3>Strings</h3>
<p><strong>Exemplo:</strong> Manipulação básica de uma string.</p>
<pre>
<code>
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;

int main() {
    char saudacao[20] = "Olá, mundo!";
    printf("%s\n", saudacao);
    return 0;
}
</code>
</pre>

<h3>Estruturas</h3>
<p><strong>Exemplo:</strong> Definição e uso de uma estrutura para armazenar dados de um livro.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

struct livro {
    char titulo[50];
    char autor[50];
    int ano;
};

int main() {
    struct livro livro1 = {"O Guia do Mochileiro das Galáxias", "Douglas Adams", 1979};
    printf("Livro: %s\nAutor: %s\nAno: %d\n", livro1.titulo, livro1.autor, livro1.ano);
    return 0;
}
</code>
</pre>

<h3>Ponteiros e Alocação Dinâmica</h3>
<p><strong>Exemplo:</strong> Uso de ponteiros e alocação dinâmica de memória para criar um vetor de inteiros.</p>
<pre>
<code>
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

int main() {
    int *vetor;
    int tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    vetor = (int*) malloc(tamanho * sizeof(int));
    
    for(int i = 0; i &lt; tamanho; i++) {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
    
    printf("Valores no vetor: ");
    for(int i = 0; i &lt; tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    free(vetor);
    return 0;
}
</code>
</pre>

<h3>Funções</h3>
<p><strong>Exemplo:</strong> Definição e chamada de uma função simples em C.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

void saudacao() {
    printf("Olá, seja bem-vindo!\n");
}

int main() {
    saudacao(); // Chamada da função
    return 0;
}
</code>
</pre>

<h3>Arquivos</h3>
<p><strong>Exemplo:</strong> Leitura e escrita de arquivos em C.</p>
<pre>
<code>
#include &lt;stdio.h&gt;

int main() {
    FILE *arquivo;
    char conteudo[] = "Hello, file!";
    
    // Escrita no arquivo
    arquivo = fopen("exemplo.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fputs(conteudo, arquivo);
    fclose(arquivo);
    
    // Leitura do arquivo
    char buffer[100];
    arquivo = fopen("exemplo.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    while(fgets(buffer, 100, arquivo) != NULL) {
        printf("%s", buffer);
    }
    fclose(arquivo);
    
    return 0;
}
</code>
</pre>

<p>Este repositório visa fornecer um recurso abrangente para iniciantes em programação, especialmente aqueles interessados em aprender a linguagem C. Através de exemplos práticos e explanações claras, os alunos podem desenvolver uma compreensão sólida dos conceitos fundamentais de programação, preparando-os para desafios mais avançados no futuro.</p>

