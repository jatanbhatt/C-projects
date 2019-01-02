#include "assignment3.h"
// Guess I could get away with not including these
// two but not having them makes gcc upset.
#include <stdio.h>
#include <stdlib.h>

#define cp(name, type)                                                         \
  type##Ptr name = malloc(sizeof(struct type));                                \
  name->key = 0;                                                               \
  name->next = NULL;

#define ff(type, name, statements, ...)                                        \
  type name(__VA_ARGS__) { statements }

#define in(pointer, value) ff(, if, return value;, !pointer)

ff(void, printSLlist, in(L, ); printf("%d ", L->key); printSLlist(L->next);
   , const SLnodePtr L);

ff(void, printHBlist, in(L, ); printf("\n%d-> ", L->key);
   printSLlist(L->bottom); printHBlist(L->next);, const HBnodePtr L);

ff(void, freeHBlist, in(L, ); freeHBlist(L->next); freeSLlist(L->bottom);
   free(L);, HBnodePtr L);

ff(void, freeSLlist, in(L, ); freeSLlist(L->next); free(L);, SLnodePtr L);

ff(static SLnodePtr, g, in(d, m); cp(l, SLnode); l->key = rand() % (max + 1);
   l->next = m; return g(d - 1, l->key, l);, int d, int max, const SLnodePtr m);

ff(static HBnodePtr, c, in(d, a); cp(e, HBnode);
   e->bottom = g(rand() % (b + 1), RAND_MAX, NULL); e->key = rand() % (f + 1);
   (e->bottom) ? e->key = e->key % (e->bottom->key + 1) : 0; e->next = a;
   return c(d - 1, b, e->key, e);, int d, int b, int f, const HBnodePtr a);

HBnodePtr createHBlist(int n, int m) { return c(n, m, RAND_MAX, NULL); }

ff(static void, mergeList, in(L, );
   ff(, while, cp(h, SLnode); h->key = L->key;
      ff(, if, h->next = i->next; i->next = h; return mergeList(i, L->next);
         , L->key >= i->key && i->next && L->key < i->next->key);
      ff(, if, i->next = h; return mergeList(i, L->next);, !i->next);
      i = i->next; freeSLlist(h);, i);
   , SLnodePtr i, const SLnodePtr L);

ff(static void, j, in(m, ); n->key = m->key; n->next = NULL; mergeList(i, n);
   return j(i, m->next, n);, SLnodePtr i, const HBnodePtr m, SLnodePtr n);

ff(SLnodePtr, flattenList, HBnodePtr k = L; cp(o, SLnode);
   ff(, while, mergeList(o, k->bottom); k = k->next;, k); cp(q, SLnode);
   j(o, L, q); freeSLlist(q); SLnodePtr r = o; SLnodePtr s = o->next; free(r);
   return s;, const HBnodePtr L);

int main(void) {
  // srand(time(NULL));
  HBnodePtr head = createHBlist(5, 10);
  printHBlist(head);
  printf("Done HB\n\n");

  SLnodePtr flat = flattenList(head);
  printSLlist(flat);
  printf("\nDone Flat\n\n");

  freeHBlist(head);
  freeSLlist(flat);
  printf("Done Cleanup\n");

  head = createHBlist(0, 0);
  printHBlist(head);
  printf("Done HB\n\n");

  flat = flattenList(head);
  printSLlist(flat);
  printf("\nDone Flat\n\n");

  freeHBlist(head);
  freeSLlist(flat);
  printf("Done Cleanup\n");
  return 0;
}
