#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float nota1, nota2;
} Aluno;

float calcular_media(float n1, float n2)
{
    return (n1 + n2) / 2.0;
}

void salvar_alunos(const char *arquivo, Aluno *alunos, int qtd)
{
    FILE *fp = fopen(arquivo, "w");
    if (!fp)
    {
        printf("Erro ao abrir ao arquivo!\n");
        return;
    }
    for (int i = 0; i < qtd; i++)
    {
        float media = calcular_media(alunos[i].nota1, alunos[i].nota2);
        fprintf(fp, "%s %.2f %.2f Média: %.2f\n", alunos[i].nota1, alunos[i].nota2, media);
    }

    fclose(fp);
    printf("Alunos gravados com sucesso em %s\n", arquivo);
}

void ler_alunos(const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    char linha[100];
    printf("\nConteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        printf("%s", linha);
    }
    fclose(fp);
}

int main()
{
    int qtd;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &qtd);
    Aluno alunos[qtd];
    for (int i = 0; i < qtd; i++)
    {
        printf("Nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("nota 2: ");
        scanf("%f", &alunos[i].nota2);
    }

    salvar_alunos("alunos.txt", alunos, qtd);
    ler_alunos("alunos.txt");
    return 0;
}