#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Укажите имя файла\n");
		return 1;
		}

	FILE *f = fopen(argv[1], "r");
	if (!f) {
		printf("Не удалось открыть файл\n");
		return 1;
		}

	int N, M;
	if (fscanf(f, "%d %d", &N, &M) != 2 || N <= 0 || M <= 0) {
		printf("Неверные размеры матрицы\n");
		fclose(f);
		return 1;
		}

	double **A = malloc(N * sizeof(double *));
	if (!A) {
		printf("Ошибка выделения памяти\n");
		fclose(f);
		return 1;
		}

	for (int i = 0; i < N; i++) {
		A[i] = malloc(M * sizeof(double));
		if (!A[i]) {
			printf("Ошибка выделения памяти\n");
			for (int k = 0; k < i; k++) free(A[k]);
			free(A);
			fclose(f);
			return 1;
			}
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (fscanf(f, "%lf", &A[i][j]) != 1) {
				printf("Ошибка чтения данных\n");

				for (int k = 0; k < N; k++) free(A[k]);
				free(A);
				fclose(f);
				return 1;
				}
			}
		}

	fclose(f);

	double *prod = malloc(N * sizeof(double));
	if (!prod) {
		printf("Ошибка выделения памяти\n");
		for (int i = 0; i < N; i++) free(A[i]);
		free(A);
		return 1;
		}

	for (int i = 0; i < N; i++) {
		double p = 1;
		for (int j = 0; j < M; j++) p *= A[i][j];
		prod[i] = p;
		}

	double S = 0;
	for (int i = 0; i < N; i++)
	S += 4.2 * (1 - prod[i]) * cos(prod[i]);

	printf("S = %.6lf\n", S);

	for (int i = 0; i < N; i++) free(A[i]);
	free(A);
	free(prod);

	return 0;
}
