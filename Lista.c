#include "stdlib.h"
#include "Lista.h"
#include "defines.h"
/**********************************************************************
TList Functions Implementations
With this lib you can create a list of any data with very simple form
By Vinicius - 2010
Use at your own risk :)
Give credits if you want
If you find bugs please contact me at vinians2006@yahoo forum
**********************************************************************/


//*********************************************************************
// Cria uma nova lista
// lista -> Lista a ser usada
// node  -> item a ser adicionado
// Obs: O primeiro NO da lista serve como inicio nao contem dados (D)
//*********************************************************************
TList *TList_new()
{
	 TList *aux;
	 aux = (TList *) malloc(sizeof(TList));
	 aux-> count = 0;
	 aux->_Next  = 0;
	 aux->_Prev  = 0;
	 aux->D      = 0; //Nao aponta pra nenhum dado.
	 aux->pointer= 0; //Nao aponta pra nenhum nó
	 aux->EOL    = TRUE;
	 aux->BOL    = TRUE;
	 return (aux);
}

//*********************************************************************
// Adiciona um item na Lista. Parametros:
// lista -> Lista a ser usada
// node  -> item a ser adicionado
//*********************************************************************
void TList_add(TList *lista, void *node)
{
   TList *Aux;
   if (lista->_Prev == 0)
      Aux = lista;
   else
      Aux = lista->_Prev; 

   Aux->_Next 		    = (TList *) malloc(sizeof(TList));
   Aux->_Next-> D 	 = node;
   Aux->_Next->_Prev  = Aux;
   Aux->_Next->_Next  = 0;
   lista->_Prev       = Aux->_Next; //Lista circular
   lista->count++;
   Aux->index = lista->count;
}

//*********************************************************************
// Retorna o total de itens de uma lista
// lista -> Lista a ser usada
//*********************************************************************
int  TList_count(TList *lista)
{
	return lista -> count;
}

//*********************************************************************
// Libera a memória usada pelos items da lista. Parametros:
// Lista -> Lista a ter a memoria liberada. 
//*********************************************************************
void TList_free(TList *lista)
{
   TList *Aux, *AHead;
   Aux = lista;
   while (Aux != 0)
   {
      AHead = Aux->_Next;
      free(Aux->D);
      free(Aux);
      Aux = AHead;
	}
}

//*********************************************************************
// Exclui um item da lista e libera memória ocupada pelo mesmo
// Lista -> Lista a a ser usada
// No    -> Item a ser Excluido 
//*********************************************************************
int  TList_delete(TList *lista, TList *node)
{
	if (lista->pointer == node) TList_first(lista);
	if (lista->_Prev == node)
	{
		//Se o NÓ for o ultimo da lista, passa pro penultimo
		lista->_Prev = node->_Prev; 
	}
   //Libera o dado armazenado no NÓ
   free(node->D); 	
   //Se tem nó a frente, imenda com o Anterior
   if (node->_Next != 0) node->_Next->_Prev = node->_Prev; 
   //Se tem nó atraz, imenda com o Posterior
   if (node->_Prev != 0) node->_Prev->_Next = node->_Next;
	//Libera o item da lista
   free(node); 
   //Diminui total de items
   if (--lista->count == 0)
	{
		lista->_Prev = 0;
		lista->_Next = 0;
		lista->EOL   = TRUE;
		lista->BOL   = TRUE;
	} 
   
   return OK;
}


//*********************************************************************
// Percorre a lista enviando cada item para uma funçao
// Lista -> Lista a ser percorrida
// func  -> Funcao que sera chamada para CADA ITEM:
// 			int func(TList *node)
// Obs: Retorne ZERO para para a iteração
//*********************************************************************
void TList_iterate(TList *lista, int (*func)(TList *node))
{
	TList *Aux;
   Aux = lista->_Next;
   while (Aux != 0)
   {
      if (func(Aux) == 0) break;
      Aux = Aux->_Next;
   }
}

//*********************************************************************
// Desloca o ponteiro para o PRIMEIRO item da lista
//*********************************************************************
void TList_first(TList *lista)
{
	if (lista->_Next == 0) 
	{
		lista->BOL = TRUE; 
		lista->EOL = TRUE;
		lista->pointer = 0;
	}
	else
	{ 
		lista->pointer = lista->_Next;
		lista->BOL = FALSE;
		lista->EOL = FALSE;
	}
}
//*********************************************************************
// Desloca o ponteiro para o PROXIMO item da lista
//*********************************************************************
void TList_next(TList *lista)
{
	if (lista->pointer != 0)
	{
		if (lista->pointer->_Next != 0)
		{
			lista->pointer = lista->pointer->_Next;
			lista->EOL = FALSE;
		} else
		{
			lista->EOL = TRUE;
		}
	}
}
//*********************************************************************
// Desloca o ponteiro para o item ANTERIOR da lista
//*********************************************************************

void TList_prev(TList *lista)
{
	if (lista->pointer->_Prev != 0)
	{
		lista->pointer = lista->pointer->_Prev;
		lista->BOL = FALSE;
	} else
		lista->BOL = TRUE;
}
