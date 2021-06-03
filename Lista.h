/*********************************************************************
TList Declarations
With this lib you can create a list of any data with very simple form
By Vinians - vinians@terra.com.br
Use at your own risk :)
Give credits if you want
If you find bugs please contact me at XCreator forum
**********************************************************************/
#ifndef LISTA_H
#define LISTA_H
typedef struct  _TList
{
	void *D; 					// Dado a ser armazenado
	struct _TList * _Next;	// Proximo item da lista
	struct _TList * _Prev;	// Item anterior da lista
	struct _TList * pointer;// Ponteiro atual da lista para uso com first, next etc
	int EOL; 					// Fim da Lista? (END OF LIST)
	int BOL; 					// Começo da Lista? (BEGIN OF LIST)
	int count;					// Total de itens
	int index; 					// posicao
} TList;
TList *TList_new(); //Cria uma nova lista

void TList_add(TList *lista, void *node);	// Adiciona um elemento na Lista

int  TList_count(TList *lista);				// Retorna o total de itens de uma lista

void TList_free(TList *lista);				// Libera a memória e destroi a lista

int  TList_delete(TList *lista, TList *node);// Deleta um Nó da lista

void TList_iterate(TList *lista, int (*func)(TList *no));									// Interage com todos os itens de uma lista

void TList_first(TList *lista);	// Move a janela para o inicio da lista

void TList_next(TList *lista);   // Move a janela para o próximo item

void TList_prev(TList *lista);   // Move a janela para o item anterior
#endif

