# Lista ligada Genérica
Lista encadeada Genérica

## Utilização
Esta lista pode ser utilizada em C padrão para adicionar qualquer tipo de informação. Funções:
```C
TList *TList_new()
TList_add(TList *lista, void *node)
TList_count(TList *lista)
TList_free(TList *lista)
TList_delete(TList *lista, TList *node)
TList_iterate(TList *lista, int (*func)(TList *node))
TList_first(TList *lista)
TList_next(TList *lista)
TList_prev(TList *lista)
```
