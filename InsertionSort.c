#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SortAscending(int v[], int tam) {
    for (int i = 1; i < tam; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && key < v[j]) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

void SortAscendingOrder(int v[], int tam) {
    for (int i = 1; i < tam; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && key < v[j]) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

void SortDescendingOrder(int v[], int tam) {
    for (int i = 1; i < tam; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && key > v[j]) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int *v = (int *)malloc(tam * sizeof(int));
    if (v == NULL) {
        printf("Falha de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 10000;
    }

    clock_t start = clock();
    SortAscending(v, tam);
    clock_t end = clock();

    double exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução do SortAscending: %.2f ms\n", exec_time);

    start = clock();
    SortAscendingOrder(v, tam);
    end = clock();
    exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar em ordem crescente: %.2f ms\n", exec_time);

    start = clock();
    SortDescendingOrder(v, tam);
    end = clock();
    exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar em ordem decrescente: %.2f ms\n", exec_time);

    free(v);
    return 0;
}
