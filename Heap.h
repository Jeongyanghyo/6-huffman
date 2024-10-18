#pragma once
#define MAX_SIZE 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_SIZE];
    int heap_size;
} HeapType;

extern HeapType* create();
extern void init(HeapType* h);
extern void insert_min_heap(HeapType* h, element item);
extern element delete_min_heap(HeapType* h);
extern void GenerateHuffmanCodes(char ch[], int freq[], int n);
extern void print_codes(TreeNode* root, int codes[], int top);
extern void GenerateHuffmanCodes(char ch[], int freq[], int n);
extern void print_codes(TreeNode* root, int codes[], int top);
