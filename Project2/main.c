#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//==============================================================zad1

void zad1(void)
{
	double a = 2;
	clock_t time1, time2;
	time1 = clock();
	int i = 0;
	while (i < pow(10, 7)) {
		i++;
	}
	time2 = clock();
	double seconds = (double)(time2 - time1)/CLOCKS_PER_SEC;
	printf("Czas pustej petli: %lf\n\n", seconds);
}


//==============================================================zad2

void zad2(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", rand() % 10);
	}
	printf("\n\n");
}


//==============================================================zad3

int iGlobal;
double dGlobal;
char cGlobal;
void zad3(void)
{
	double dLocal;
	static char staticCLocal;

	double a;
	int b;
	static char c;

	double* wa = &a;
	int* wb = &b;
	char cLocal;
	static char* wc = &c;
	printf("int \tlokalnie: %p \tint \tglobalnie: %p\ndouble \tlokalnie: %p\tdouble \tglobalnie: %p\nchar \tlokalnie: %p\tchar \tglobalnie: %p\n\t\t\t\tchar \tstatycznie: %p\n\n", wb, &iGlobal, wa, &dGlobal, &cLocal, &cGlobal, wc);
}

//==============================================================zad4

void zad4(void)
{
	int* pamiec;
	int N = 1;
	while (1) {
		pamiec = (int*)malloc(50 * pow(10, 6) * N);
		if (!pamiec) {
			printf("Nie udalo sie zaalokowac bloku %dMB\n", 50 * (N));
			break;
		}
		free(pamiec);
		N++;
	}
	//alokowanie duzych blokow pamieci zajmuje znaczna ilosc czasu
}

int main()
{
	zad1();
	zad2();
	zad3();
	zad4();

	return 0;
}