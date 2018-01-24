#include "SortingProgram.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

///BUSCA BINARIA
int buscaBinaria(FILE *arq, int max, int search)
{
   int c, first, last, middle, array[100];

   int i, vector[100001];
    if(max == 100)
    {
        arq = fopen("selec_100.txt", "r");

    }

    if(max == 1000)
    {
        arq = fopen("selec_1000.txt", "r");

    }

    if(max == 10000)
    {
        arq = fopen("selec_10000.txt", "r");

    }
    if(max == 100000)
    {
        arq = fopen("selec_100000.txt", "r");

    }

    //ADICIONAR NUMEROS DO ARQUIVO NUM VETOR;
    if(arq == NULL)
        EXIT_FAILURE;

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
    }

    fclose(arq);

   first = 0;
   last = max - 1;
   middle = (first+last)/2;

   while (first <= last) {
      if (vector[middle] < search)
         first = middle + 1;
      else if (vector[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);

   return 0;
}

///BUSCA SEQUENCIAL
void buscaSequencial(FILE *arq, int max, long long int find_this)
{
    int i, vector[100001];
    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");

    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");

    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");

    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");

    }

    //ADICIONAR NUMEROS DO ARQUIVO NUM VETOR;
    if(arq == NULL)
        EXIT_FAILURE;

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
    }

    fclose(arq);
    for(i = 0; i < max; i++)
    {
        if(vector[i] == find_this)
        {
            printf("Achou %d na posição %d\n", find_this, i);
            return 1;
        }
    }
    printf("Nao achou\n");
    return 0;
}


///FUNÇÃO DO MERGE SORT
int intercala(int vet[], int inicio, int meio, int fim, long long int *trocas, long long int *comparacoes)
{

    int com1 = inicio, com2 = meio + 1, comAux = 0;
    int aux[fim];

    while (com1 <= meio && com2 <= fim)
    {
        if (vet[com1] <= vet[com2])
        {
            aux[comAux] = vet[com1];
            com1++;
        }
        else
        {
            aux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
        comparacoes++;
    }
    while (com1 <= meio)
    {
        aux[comAux] = vet[com1];
        comAux++;
        com1++;
        //comparacao(comparacoes);
    }
    while (com2 <= fim)
    {
        aux[comAux] = vet[com2];
        comAux++;
        com2++;
        //comparacao(comparacoes);
    }

    for (comAux = inicio; comAux <= fim; comAux++)
    {
        vet[comAux] = aux[comAux - inicio];
        *trocas += 1;
    }
}
///MERGE SORT
void merge_sort(int vet[], int inicio, int tam, long long int *trocas, long long int *comparacoes)
{
    int meio;

    if (inicio < tam)
    {
        meio = (inicio + tam) / 2;
        merge_sort(vet, inicio, meio, trocas, comparacoes);
        merge_sort(vet, meio + 1, tam, trocas, comparacoes);
        intercala(vet, inicio, meio, tam, trocas, comparacoes);
    }
}

///CHAMA MERGE SORT
void chamaMergeSort(FILE *arq, int max)
{
    clock_t start, end;
    double cpu_time_used;

    int vector[100001];
    int i;
    long long int *trocas = 0;
    long long int *compara = 0;

    start = clock();

    FILE *merge_100;
    FILE *merge_1000;
    FILE *merge_10000;
    FILE *merge_100000;

    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");
        merge_100 = fopen("merge_100.txt", "w");
    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");
        merge_1000 = fopen("merge_1000.txt", "w");
    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");
        merge_10000 = fopen("merge_10000.txt", "w");
    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");
        merge_100000 = fopen("merge_100000.txt", "w");
    }

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
    }
    merge_sort(vector, 0, max, &trocas, &compara);

    for(i = 0; i < max; i++)
        {
            if(max == 100)
            fprintf(merge_100, "%ld ", vector[i]);

            if(max == 1000)
            fprintf(merge_1000, "%ld ", vector[i]);

            if(max == 10000)
            fprintf(merge_10000, "%ld ", vector[i]);

            if(max == 100000)
            fprintf(merge_100000, "%ld ", vector[i]);
        }
        end = clock();

        printf("MERGE SORT\nTempo: %ld\nTrocas: %lld\nComparacoes: %lld\n", cpu_time_used/1000, trocas, compara);
}

///QUICK SORT
void QuickSort(int vector[], int max, long long int *trocas, long long int *compara)
{
    //long int vector[100001];
    int i, j;
  if (max < 2) return;

  int pivot = vector[max / 2];

  for (i = 0, j = max - 1; ; i++, j--) {
    while (vector[i] < pivot)
    {
        i++;
        compara++;
    }

    while (vector[j] > pivot)
    {
        j--;
        compara++;
    }

    if (i >= j)
    {
        compara++;
        break;
    }

    int temp = vector[i];
    vector[i]     = vector[j];
    vector[j]     = temp;
    trocas++;
  }

  QuickSort(vector, i, trocas, compara);
  QuickSort(vector + i, max - i, trocas, compara);
}

///CHAMA QUICK SORT
void chamaQuickSort(FILE *arq, int max)
{
    clock_t start, end;
    double cpu_time_used;

    int vector[100001];
    int i;
    long long int *trocas = 0;
    long long int *compara = 0;

    start = clock();

    FILE *quick_100;
    FILE *quick_1000;
    FILE *quick_10000;
    FILE *quick_100000;

    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");
        quick_100 = fopen("quick_100.txt", "w");
    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");
        quick_1000 = fopen("quick_1000.txt", "w");
    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");
        quick_10000 = fopen("quick_10000.txt", "w");
    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");
        quick_100000 = fopen("quick_100000.txt", "w");
    }

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);

    }
    QuickSort(vector, max, &trocas, &compara);

    for(i = 0; i < max; i++)
        {
            if(max == 100)
            fprintf(quick_100, "%ld ", vector[i]);

            if(max == 1000)
            fprintf(quick_1000, "%ld ", vector[i]);

            if(max == 10000)
            fprintf(quick_10000, "%ld ", vector[i]);

            if(max == 100000)
            fprintf(quick_100000, "%ld ", vector[i]);
        }
    end = clock();
    printf("QUICK SORT\nTempo: %ld\nTrocas: %lld\nComparacoes: %lld\n", cpu_time_used, trocas, compara);

}

///RADIX SORT
void radixsort(FILE *arq, int max) {
    clock_t start, end;
    double cpu_time_used;
    int i;
    int *b;
    int exp = 1;
    long int vector[100001];
    long long int trocas = 0, compara = 0;

    start = clock();

    FILE *radix_100;
    FILE *radix_1000;
    FILE *radix_10000;
    FILE *radix_100000;

    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");
        radix_100 = fopen("radix_100.txt", "w");
    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");
        radix_1000 = fopen("radix_1000.txt", "w");
    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");
        radix_10000 = fopen("radix_10000.txt", "w");
    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");
        radix_100000 = fopen("radix_100000.txt", "w");
    }

    //ADICIONAR NUMEROS DO ARQUIVO NUM VETOR;
    if(arq == NULL)
        EXIT_FAILURE;

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
    }

    fclose(arq);

    int maior = vector[0];
    b = (int *)calloc(max, sizeof(int));

    for (i = 0; i < max; i++) {
        if (vector[i] > maior)

    	    maior = vector[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < max; i++)
    	    bucket[(vector[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = max - 1; i >= 0; i--)
    	    b[--bucket[(vector[i] / exp) % 10]] = vector[i];
    	for (i = 0; i < max; i++)
    	    vector[i] = b[i];
    	exp *= 10;
    }

    free(b);

    for(i = 0; i < max; i++)
    {
        if(max == 100)
        fprintf(radix_100, "%ld ", vector[i]);

        if(max == 1000)
        fprintf(radix_1000, "%ld ", vector[i]);

        if(max == 10000)
        fprintf(radix_10000, "%ld ", vector[i]);

        if(max == 100000)
        fprintf(radix_100000, "%ld ", vector[i]);
    }
    end = clock();

    printf("RADIX SORT\nTempo: %ld\n", cpu_time_used);
}


///BUBBLE SORT PROGRAM
void BubbleSort (FILE *arq, int max)
{
    clock_t start, end;
    double cpu_time_used;
    int k, j, i, aux;
    long long int trocas = 0, compara = 0;
    long int vector[100001];

    start = clock();

    FILE *bubble_100;
    FILE *bubble_1000;
    FILE *bubble_10000;
    FILE *bubble_100000;

    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");
        bubble_100 = fopen("bubble_100.txt", "w");
    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");
        bubble_1000 = fopen("bubble_1000.txt", "w");
    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");
        bubble_10000 = fopen("bubble_10000.txt", "w");
    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");
        bubble_100000 = fopen("bubble_100000.txt", "w");
    }

    //ADICIONAR NUMEROS DO ARQUIVO NUM VETOR;
    if(arq == NULL)
        EXIT_FAILURE;

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
    }

    fclose(arq);

    for (k = max - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            if (vector[j] > vector[j + 1]) {
                    compara++;
                aux          = vector[j];
                vector[j]     = vector[j + 1];
                vector[j + 1] = aux;
                trocas++;
            }
            else
                compara++;
        }
    }

    for(i = 0; i < max; i++)
    {
        if(max == 100)
        fprintf(bubble_100, "%ld ", vector[i]);

        if(max == 1000)
        fprintf(bubble_1000, "%ld ", vector[i]);

        if(max == 10000)
        fprintf(bubble_10000, "%ld ", vector[i]);

        if(max == 100000)
        fprintf(bubble_100000, "%ld ", vector[i]);
    }
    end = clock();

    printf("BUBBLE SORT\nTempo: %ld\nTrocas: %lld\nComparacoes: %lld\n", cpu_time_used, trocas, compara);

}

///INSERTION SORT PROGRAM
void insertionSort(FILE *arq, int max)
{
    int i, j, atual;
    clock_t start, end;
    double cpu_time_used;
    long long int trocas = 0, compara = 0;
	long int vector[100001];

	start = clock();

    FILE *insertion_100;
    FILE *insertion_1000;
    FILE *insertion_10000;
    FILE *insertion_100000;

    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");
        insertion_100 = fopen("insertion_100.txt", "w");
    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");
        insertion_1000 = fopen("insertion_1000.txt", "w");
    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");
        insertion_10000 = fopen("insertion_10000.txt", "w");
    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");
        insertion_100000 = fopen("insertion_100000.txt", "w");
    }

    //ADICIONAR NUMEROS DO ARQUIVO NUM VETOR;
    if(arq == NULL)
        EXIT_FAILURE;

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
        //printf("%d ", vector[i]);
    }

    fclose(arq);

	for (i = 1; i < max; i++) {
		atual = vector[i];


		for (j = i - 1; (j >= 0) && (atual < vector[j]); j--) {
			vector[j + 1] = vector[j];
			trocas++;
			compara++;
        }

		vector[j+1] = atual;
		trocas++;
	}

	for(i = 0; i < max; i++)
    {
        if(max == 100)
        fprintf(insertion_100, "%ld ", vector[i]);

        if(max == 1000)
        fprintf(insertion_1000, "%ld ", vector[i]);

        if(max == 10000)
        fprintf(insertion_10000, "%ld ", vector[i]);

        if(max == 100000)
        fprintf(insertion_100000, "%ld ", vector[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("INSERTION SORT\nTempo: %ld\nTrocas: %lld\nComparacoes: %lld\n", cpu_time_used, trocas, compara);

}

///SELECTION SORT PROGRAM
void SelectionSort(FILE *arq, int max)
{
    int i, j, min, aux;
    clock_t start, end;
    double cpu_time_used;
    long long int trocas = 0, compara = 0;
    long int vector[100001];

    start = clock();

    FILE *selec_100;
    FILE *selec_1000;
    FILE *selec_10000;
    FILE *selec_100000;

    if(max == 100)
    {
        arq = fopen("random_100.txt", "r");
        selec_100 = fopen("selec_100.txt", "w");
    }

    if(max == 1000)
    {
        arq = fopen("random_1000.txt", "r");
        selec_1000 = fopen("selec_1000.txt", "w");
    }

    if(max == 10000)
    {
        arq = fopen("random_10000.txt", "r");
        selec_10000 = fopen("selec_10000.txt", "w");
    }
    if(max == 100000)
    {
        arq = fopen("random_100000.txt", "r");
        selec_100000 = fopen("selec_100000.txt", "w");
    }

    //ADICIONAR NUMEROS DO ARQUIVO NUM VETOR;
    if(arq == NULL)
        EXIT_FAILURE;

    for(i = 0; i < max; i++)
    {
        fscanf(arq, "%d ", &vector[i]);
    }

    fclose(arq);

    //CODIGO SELECTION SORT
    for(i = 0; i < (max - 1); i++)
    {
        min = i;
        for(j = i+1; j < max; j++)
        {
            if(vector[j] < vector[min])
            {
                min = j;
                compara++;
            }
        }
        if(i != min)
        {
            aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
            trocas++;
        }
    }

    for(i = 0; i < max; i++)
    {
        if(max == 100)
        fprintf(selec_100, "%ld ", vector[i]);

        if(max == 1000)
        fprintf(selec_1000, "%ld ", vector[i]);

        if(max == 10000)
        fprintf(selec_10000, "%ld ", vector[i]);

        if(max == 100000)
        fprintf(selec_100000, "%ld ", vector[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("SELECTION SORT\nTempo: %ld\nTrocas: %lld\nComparacoes: %lld\n", cpu_time_used, trocas, compara);
}

void geraRandom(int tamanho, FILE *arq)
{
    srand(time(NULL));
    for(count = 0; count < tamanho; count++)
        serie[count] = rand();

    if(tamanho == 100)
    {
        for(count = 0; count < 100; count++)
        fprintf(arq, "%d ", serie[count]);
    }

    if(tamanho == 1000)
    {
        for(count = 0; count < 1000; count++)
        fprintf(arq, "%d ", serie[count]);
    }

    if(tamanho == 10000)
    {
        for(count = 0; count < 10000; count++)
        fprintf(arq, "%d ", serie[count]);
    }

    if(tamanho == 100000)
    {
        for(count = 0; count < 100000; count++)
        fprintf(arq, "%d ", serie[count]);
    }
}

int testeDeAbertura(FILE *arq)
{
    if(arq == NULL)
        return 1;
}
