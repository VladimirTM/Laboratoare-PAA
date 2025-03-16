#include<stdint.h>

#define MAXNODES 100

typedef uint8_t TKey;

typedef struct {
	uint8_t primFiu, frateDreapta;
	TKey key;
}TNode;

typedef uint8_t TNodeRef;

typedef struct {
	TNode nodes[MAXNODES];
	uint8_t size; //tree size = number of nodes in the tree	
}TTree;

TTree InitTree(TTree a);

TTree InsertNode(TTree a, TNodeRef  primFiu, TNodeRef frateDreapta, TKey key);

void printArray(TTree a);

void printNode(TNode node);

TKey nodeKey(TTree a, TNodeRef noderef);

TNode nodeByRef(TTree a, TNodeRef noderef);

TNodeRef getRoot(TTree a);

void preordine(TTree arbore, TNodeRef radacina);

void inordine(TTree arbore, TNodeRef radacina);

void postordine(TTree arbore, TNodeRef radacina);