#include <stdio.h>

int countDivs(int num, int i) {
	if (i < 1)
		return 0;
	return(num % i == 0 ? 1 : 0) + countDivs(num, i - 1);
	}

void findNumb(int n, int m, int k, int curr, int* found) {
	if (curr > m)
		return;

	if(countDivs(curr, curr - 1) == k) {
		printf("%d", curr);
	*found = 1;
	}

	findNumb(n, m , k, curr + 1, found);
}

int main() {
	int N,M,K;

	printf("Введите N, M, K: ");
	scanf("%d %d %d", &N, &M, &K);

	if (N <= 0 || M <= 0 || K < 0 || N > M) {
		printf("Ошибка ввода данных\n");
		return 1;
	}

	printf("Цепочка чисел: ");
	int found = 0;
	findNumb(N, M, K, N, &found);

	if (!found) {
		printf("Чисел не найдено");
	}

	printf("\n");
	return 0;
} 

