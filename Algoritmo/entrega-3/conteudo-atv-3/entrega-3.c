#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void limparBuffer(void)
{
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
    }
}

int salvarDados(const char nomeArquivo[], int numeros[])
{
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel salvar o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    for (int i = 0; i < TAMANHO; i++)
    {
        fprintf(arquivo, "%d\n", numeros[i]);
    }

    fclose(arquivo);
    return 1;
}

int carregarDados(const char nomeArquivo[], int numeros[])
{
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        return 0;
    }

    for (int i = 0; i < TAMANHO; i++)
    {
        if (fscanf(arquivo, "%d", &numeros[i]) != 1)
        {
            fclose(arquivo);
            return 0;
        }
    }

    fclose(arquivo);
    return 1;
}

void mostrarNumeros(int numeros[])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", numeros[i]);
    }

    printf("\n");
}

void copiarNumeros(int original[], int copia[])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        copia[i] = original[i];
    }
}

void bubbleSort(int numeros[])
{
    for (int i = 0; i < TAMANHO - 1; i++)
    {
        for (int j = 0; j < TAMANHO - 1 - i; j++)
        {
            if (numeros[j] > numeros[j + 1])
            {
                int auxiliar = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = auxiliar;
            }
        }
    }
}

void insertionSort(int numeros[])
{
    for (int i = 1; i < TAMANHO; i++)
    {
        int atual = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] > atual)
        {
            numeros[j + 1] = numeros[j];
            j--;
        }

        numeros[j + 1] = atual;
    }
}

void selectionSort(int numeros[])
{
    for (int i = 0; i < TAMANHO - 1; i++)
    {
        int posicaoMenor = i;

        for (int j = i + 1; j < TAMANHO; j++)
        {
            if (numeros[j] < numeros[posicaoMenor])
            {
                posicaoMenor = j;
            }
        }

        if (posicaoMenor != i)
        {
            int auxiliar = numeros[i];
            numeros[i] = numeros[posicaoMenor];
            numeros[posicaoMenor] = auxiliar;
        }
    }
}

void intercalar(int numeros[], int inicio, int meio, int fim)
{
    int quantidade = fim - inicio + 1;
    int *auxiliar = malloc(quantidade * sizeof(int));

    if (auxiliar == NULL)
    {
        printf("Erro ao reservar memoria para o Merge Sort.\n");
        exit(1);
    }

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim)
    {
        if (numeros[i] <= numeros[j])
        {
            auxiliar[k++] = numeros[i++];
        }
        else
        {
            auxiliar[k++] = numeros[j++];
        }
    }

    while (i <= meio)
    {
        auxiliar[k++] = numeros[i++];
    }

    while (j <= fim)
    {
        auxiliar[k++] = numeros[j++];
    }

    for (i = 0; i < quantidade; i++)
    {
        numeros[inicio + i] = auxiliar[i];
    }

    free(auxiliar);
}

void mergeSort(int numeros[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(numeros, inicio, meio);
        mergeSort(numeros, meio + 1, fim);

        intercalar(numeros, inicio, meio, fim);
    }
}

// Separa os numeros menores e maiores em relacao ao pivo
int particionar(int numeros[], int inicio, int fim)
{
    int pivo = numeros[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (numeros[j] <= pivo)
        {
            i++;

            int auxiliar = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = auxiliar;
        }
    }

    int auxiliar = numeros[i + 1];
    numeros[i + 1] = numeros[fim];
    numeros[fim] = auxiliar;

    return i + 1;
}

// Quick Sort: ordena as partes separadas pelo pivo
void quickSort(int numeros[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int posicaoPivo = particionar(numeros, inicio, fim);

        quickSort(numeros, inicio, posicaoPivo - 1);
        quickSort(numeros, posicaoPivo + 1, fim);
    }
}

// Executa o algoritmo escolhido e salva o resultado
void ordenarNumeros(int dados[], int opcao)
{
    int resultado[TAMANHO];

    copiarNumeros(dados, resultado);

    printf("\nNumeros antes da ordenacao:\n");
    mostrarNumeros(dados);

    switch (opcao)
    {
        case 1:
            bubbleSort(resultado);
            printf("\nMetodo escolhido: Bubble Sort\n");
            break;

        case 2:
            insertionSort(resultado);
            printf("\nMetodo escolhido: Insertion Sort\n");
            break;

        case 3:
            selectionSort(resultado);
            printf("\nMetodo escolhido: Selection Sort\n");
            break;

        case 4:
            mergeSort(resultado, 0, TAMANHO - 1);
            printf("\nMetodo escolhido: Merge Sort\n");
            break;

        case 5:
            quickSort(resultado, 0, TAMANHO - 1);
            printf("\nMetodo escolhido: Quick Sort\n");
            break;

        default:
            printf("Opcao invalida!\n");
            return;
    }

    printf("\nNumeros em ordem crescente:\n");
    mostrarNumeros(resultado);

    if (salvarDados("ordenado.txt", resultado))
    {
        printf("Resultado salvo no arquivo ordenado.txt.\n");
    }
}

void alterarNumero(int dados[])
{
    int posicao;
    int novoNumero;

    printf("\nNumeros cadastrados:\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Posicao %d: %d\n", i + 1, dados[i]);
    }

    printf("\nQual posicao deseja alterar (1 a %d)? ", TAMANHO);

    if (scanf("%d", &posicao) != 1)
    {
        printf("Digite uma posicao valida.\n");
        limparBuffer();
        return;
    }

    if (posicao < 1 || posicao > TAMANHO)
    {
        printf("Essa posicao nao existe.\n");
        return;
    }

    printf("Digite o novo numero: ");

    if (scanf("%d", &novoNumero) != 1)
    {
        printf("Valor invalido. Digite um numero inteiro.\n");
        limparBuffer();
        return;
    }

    dados[posicao - 1] = novoNumero;

    if (salvarDados("dados.txt", dados))
    {
        printf("\nNumero alterado com sucesso!\n");
        printf("O arquivo dados.txt foi atualizado.\n");

        printf("\nLista atualizada:\n");
        mostrarNumeros(dados);
    }
}

int main(void)
{
    int dados[TAMANHO];
    int opcao;

    if (!carregarDados("dados.txt", dados))
    {
        printf("Nao foi possivel encontrar dados validos em dados.txt.\n");
        printf("Vamos cadastrar %d numeros inteiros.\n\n", TAMANHO);

        for (int i = 0; i < TAMANHO; i++)
        {
            printf("Digite o numero %d: ", i + 1);

            if (scanf("%d", &dados[i]) != 1)
            {
                printf("Entrada invalida. Execute o programa novamente.\n");
                return 1;
            }
        }

        if (!salvarDados("dados.txt", dados))
        {
            printf("Nao foi possivel criar o arquivo de dados.\n");
            return 1;
        }

        printf("\nArquivo dados.txt criado com sucesso!\n");

        if (!carregarDados("dados.txt", dados))
        {
            printf("Ocorreu um erro ao ler os dados salvos.\n");
            return 1;
        }
    }

    printf("\nNumeros carregados do arquivo:\n");
    mostrarNumeros(dados);

    do
    {
        printf("\n-Selecione uma das opções de ordenação-\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("6 - Alterar um numero\n");
        printf("0 - Sair do programa\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida. Digite uma opcao numerica.\n");
            limparBuffer();
            opcao = -1;
            continue;
        }

        switch (opcao)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                ordenarNumeros(dados, opcao);
                break;

            case 6:
                alterarNumero(dados);
                break;

            case 0:
                printf("\nPrograma encerrado. Ate mais!\n");
                break;

            default:
                printf("\nOpcao nao encontrada. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}