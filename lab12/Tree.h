#pragma once
#include<iostream>
#include <Windows.h>
using namespace std;

struct tNode {
	int data;
	int num;
	tNode* left, * right;
};
void print(tNode*, int);
tNode* input(tNode*, int);
tNode* del(tNode*, int);
tNode* search(int key, tNode* leaf);
void tClear(tNode*);
void Directbypass(tNode*);
void Symmetricbypass(tNode*);
void Reversebypass(tNode*);
int Correct_Input_Integer();
int AVL(tNode* root);
int CountTopK(tNode* Root);
