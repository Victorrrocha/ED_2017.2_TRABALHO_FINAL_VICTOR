#ifndef SORTINGPROGRAM_H_INCLUDED
#define SORTINGPROGRAM_H_INCLUDED

int serie[100001];
int random, count;

int buscaBinaria(FILE *arq, int max, int search);

void buscaSequencial(FILE *arq, int max, long long int find_this);

int intercala(int vet[], int inicio, int meio, int fim, long long int *trocas, long long int *comparacoes);

void merge_sort(int vet[], int inicio, int tam, long long int *trocas, long long int *comparacoes);

void chamaMergeSort(FILE *arq, int max);

void QuickSort(int vector[], int max, long long int *trocas, long long int *compara);

void chamaQuickSort(FILE *arq, int max);

void radixsort(FILE *arq, int max);

void BubbleSort (FILE *arq, int max);

void insertionSort(FILE *arq, int max);

void SelectionSort(FILE *arq, int max);

void geraRandom(int tamanho, FILE *arq);

#endif // SORTINGPROGRAM_H_INCLUDED
