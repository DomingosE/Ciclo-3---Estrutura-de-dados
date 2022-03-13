#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct celula{
	int x;
	struct celula *proximo;
}cel;
int main()
{
	int a;
	setlocale (LC_ALL, "Portuguese");
	cel *inicio, *fim, *anterior;
	inicio= (cel*)malloc(sizeof(cel));
	if (inicio==NULL) return 0;
	fim=inicio;
	while(1)
	{
		scanf ("%d", &fim ->x);
		if (fim -> x == 0) break;
		fim -> proximo = (cel *) malloc(sizeof(cel));
		if (fim -> proximo == NULL) return 0;
		fim = fim -> proximo;
	}
	fim -> proximo = NULL;
	fim=inicio;
	while (fim -> proximo != NULL)
	{
		printf ("%d", fim -> x);
		fim = fim -> proximo;
	}
	printf ("\nInforme o valor a ser excluído da lista:");
	scanf ("%d", &a);
	if (inicio -> x == a)
	{
		anterior=inicio;
		inicio=inicio->proximo;
		free (anterior);
	}
	else {
		fim=inicio;
		while (fim->x!=a&&fim->proximo!=NULL)
		{
			anterior=fim;
			fim=fim->proximo;
		}
		if  (fim -> x==a)
		{
			anterior->proximo=fim->proximo;
			free(fim);
		}
		else printf ("\nNão existe esse valor na lista. Os valores existentes na lista são: ");	
		}
	fim=inicio;
	while (fim -> proximo != NULL)
	{
		printf ("%d", fim -> x);
		fim = fim -> proximo;
	}
}
