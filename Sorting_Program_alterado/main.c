#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "SortingProgram.h"

int main()
{
    FILE *arq_100;
    FILE *arq_1000;
    FILE *arq_10000;
    FILE *arq_100000;

    int escolha;
    printf("======================================\n\tPROGRAMA DE ORDENACAO\n");
    printf("1 - GERAR ARQUIVO ALEATORIO.\n");
    printf("0 - SAIR\n");
    scanf("%d", &escolha);

    if(escolha == 1)
    {
        while(escolha == 1)
        {
            int outra_escolha, ordena;
        printf("Quantos elementos? (100,1000,10000,100000)\n");
        scanf("%d", &outra_escolha);

        switch(outra_escolha)
        {
        case 100:

            arq_100 = fopen("random_100.txt", "w");
            if(testeDeAbertura(arq_100) == 1)
                return 0;
            geraRandom(100, arq_100);
            fclose(arq_100);
            printf("Arquivo gerado com sucesso!\n");
            printf("Escolha metodo de ordenacao:\n\n");
            printf("1 - SELECTION SORT\n2 - INSERTION SORT\n3 - BUBBLE SORT\n4 - RADIX SORT\n5 - QUICK SORT\n6 - MERGE SORT\n");
            scanf("%d", &ordena);
            switch(ordena)
            {
            case 1:
                SelectionSort(arq_100, 100);
                break;
            case 2:
                insertionSort(arq_100, 100);
                break;
            case 3:
                BubbleSort(arq_100, 100);
                break;
            case 4:
                radixsort(arq_100, 100);
                break;
            case 5:
                chamaQuickSort(arq_100, 100);
                break;
            case 6:
                chamaMergeSort(arq_100, 100);
                break;
            }
            break;

        case 1000:

            arq_1000 = fopen("random_1000.txt", "w");
            if(testeDeAbertura(arq_1000) == 1)
                return 0;
            geraRandom(1000, arq_1000);
            fclose(arq_1000);
            printf("Arquivo gerado com sucesso!\n");
            printf("Escolha metodo de ordenacao:\n\n");
            printf("1 - SELECTION SORT\n2 - INSERTION SORT\n3 - BUBBLE SORT\n4 - RADIX SORT\n5 - QUICK SORT\n6 - MERGE SORT\n");
            scanf("%d", &ordena);
            switch(ordena)
            {
            case 1:
                SelectionSort(arq_1000, 1000);
                break;
            case 2:
                insertionSort(arq_1000, 1000);
                break;
            case 3:
                BubbleSort(arq_1000, 1000);
                break;
            case 4:
                radixsort(arq_1000, 1000);
                break;
            case 5:
                chamaQuickSort(arq_1000, 1000);
                break;
            case 6:
                chamaMergeSort(arq_1000, 1000);
                break;
            }
            break;

        case 10000:

            arq_10000 = fopen("random_10000.txt", "w");
            if(testeDeAbertura(arq_10000) == 1)
                return 0;
            geraRandom(10000, arq_10000);
            fclose(arq_10000);
            printf("Arquivo gerado com sucesso!\n");
            printf("Escolha metodo de ordenacao:\n\n");
            printf("1 - SELECTION SORT\n2 - INSERTION SORT\n3 - BUBBLE SORT\n4 - RADIX SORT\n5 - QUICK SORT\n6 - MERGE SORT\n");
            scanf("%d", &ordena);
            switch(ordena)
            {
            case 1:
                SelectionSort(arq_10000, 10000);
                break;
            case 2:
                insertionSort(arq_10000, 10000);
                break;
            case 3:
                BubbleSort(arq_10000, 10000);
                break;
            case 4:
                radixsort(arq_10000, 10000);
                break;
            case 5:
                chamaQuickSort(arq_10000, 10000);
                break;
            case 6:
                chamaMergeSort(arq_10000, 10000);
                break;
            }
            break;

        case 100000:
            arq_100000 = fopen("random_100000.txt", "w");
            if(testeDeAbertura(arq_100000) == 1)
                return 0;
            geraRandom(100000, arq_100000);
            fclose(arq_100000);
            printf("Arquivo gerado com sucesso!\n");
            printf("Escolha metodo de ordenacao:\n\n");
            printf("1 - SELECTION SORT\n2 - INSERTION SORT\n3 - BUBBLE SORT\n4 - RADIX SORT\n5 - QUICK SORT\n6 - MERGE SORT\n");
            scanf("%d", &ordena);
            switch(ordena)
            {
            case 1:
                SelectionSort(arq_100000, 100000);
                break;
            case 2:
                insertionSort(arq_10000, 100000);
                break;
            case 3:
                BubbleSort(arq_100000, 100000);
                break;
            case 4:
                radixsort(arq_100000, 100000);
                break;
            case 5:
                chamaQuickSort(arq_100000, 100000);
                break;
            case 6:
                chamaMergeSort(arq_100000, 100000);
                break;
            }
            break;
        }
    printf("Deseja fazer outra operacao? (SIM - 1, NAO - 0)\n");
    scanf("%d", &escolha);
    }
        }


    else if(escolha == 0)
    {
        printf("OBRIGARDEN E VOLTE SEMPRE\n");
        return 0;
    }


    ///TESTE SEQUENCIAL SEARCH
    //buscaSequencial(arq_100, 100, 4428);
    ///TESTE BUSCA BINARIA;
    //buscaBinaria(arq_100, 100, 163);
    return 0;
}
