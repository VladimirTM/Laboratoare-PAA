#include<stdio.h>
#include<stdint.h>
#include"arborG.h"


TTree InitTree(TTree a) {
	for (int i = 0; i < MAXNODES; i++) {
		a.nodes[i].primFiu = 0;
		a.nodes[i].frateDreapta = 0;
		a.nodes[i].key = 0;
	}
	a.size = 0;
	return a;
}

TTree InsertNode(TTree a, TNodeRef  primFiu, TNodeRef frateDreapta, TKey key) {
	a.size++;
	a.nodes[a.size].key = key;
	a.nodes[a.size].primFiu = primFiu;
	a.nodes[a.size].frateDreapta = frateDreapta;
	return a;
}

void printArray(TTree a) {
	printf("\nIndex:           ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", i);
	}
	printf("\nKey:             ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", a.nodes[i].key);
	}
	printf("\nFirst Child:     ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", a.nodes[i].primFiu);
	}
	printf("\nRight Sibling:   ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", a.nodes[i].frateDreapta);
	}
	printf("\n------------------------------------\n");
}

void printNode(TNode node) {
	printf("\nKey: %d\n", node.key);
}

TNodeRef getRoot(TTree a) {
	if (a.size < 1) return 0;
	return 1;
}
TNodeRef findNodeIndex(TTree a, TNode node) {
	for (uint8_t i = 0; i <= a.size; i++) {
		if (a.nodes[i].key == node.key && a.nodes[i].primFiu == node.primFiu && a.nodes[i].frateDreapta == a.nodes[i].frateDreapta) return i;
	}
	return 0;
}

TKey nodeKey(TTree a, TNodeRef noderef) {
	if (noderef > a.size) return 0;
	return a.nodes[noderef].key;
}

TNode nodeByRef(TTree a, TNodeRef noderef) {
	return a.nodes[noderef];
}

void preordine(TTree arbore, TNodeRef radacina)
{
	printNode(nodeByRef(arbore, radacina));
	TNodeRef fiuStanga = arbore.nodes[radacina].primFiu;
	if (fiuStanga != 0)
	{
		preordine(arbore, fiuStanga);
	}
	TNodeRef fiuDreapta = fiuStanga;
	while ((fiuDreapta = arbore.nodes[fiuDreapta].frateDreapta) != 0)
	{
		preordine(arbore, fiuDreapta);
	}
}

void inordine(TTree arbore, TNodeRef radacina)
{
	TNodeRef fiuStanga = arbore.nodes[radacina].primFiu;
	if (fiuStanga != 0)
	{
		inordine(arbore, fiuStanga);
	}
	printNode(nodeByRef(arbore, radacina));
	TNodeRef fiuDreapta = fiuStanga;
	while ((fiuDreapta = arbore.nodes[fiuDreapta].frateDreapta) != 0)
	{
		inordine(arbore, fiuDreapta);
	}
}

void postordine(TTree arbore, TNodeRef radacina)
{
	TNodeRef fiuStanga = arbore.nodes[radacina].primFiu;
	if (fiuStanga != 0)
	{
		postordine(arbore, fiuStanga);
	}
	TNodeRef fiuDreapta = fiuStanga;
	while ((fiuDreapta = arbore.nodes[fiuDreapta].frateDreapta) != 0)
	{
		postordine(arbore, fiuDreapta);
	}
	printNode(nodeByRef(arbore, radacina));
}