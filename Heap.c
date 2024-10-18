#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#define MAX_ELEMENT 200

//동적 할당으로 HeapType 구조체 생성
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

//힙 초기화
void init(HeapType* h) {
    h->heap_size = 0;
}

//허프만 코드 출력
void print_array(int codes[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", codes[i]);
    printf("\n");
}

//힙에 최소 원소 삽입
void insert_min_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);
    while (i != 1 && item.key < h->heap[i / 2].key) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; 
}

//힙에서 최소 원소 삭제
element delete_min_heap(HeapType* h) {
    element item = h->heap[1];
    element temp = h->heap[(h->heap_size)--];
    int parent = 1, child = 2;

    while (child <= h->heap_size) {
        if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key) {
            child++;
        }
        if (temp.key <= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

//트리 노드 생성
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    node->weight = left->weight + right->weight;
    node->ch = '\0';
    return node;
}

//리프 노드인지 확인
int is_leaf(TreeNode* root) {
    return !(root->left) && !(root->right);
}

//허프만 코드 출력
void print_codes(TreeNode* root, int codes[], int top) {
    if (root->left) {
        codes[top] = 1; 
        print_codes(root->left, codes, top + 1);
    }
    if (root->right) {
        codes[top] = 0; 
        print_codes(root->right, codes, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c: ", root->ch);
        print_array(codes, top);
    }
}

//허프만 트리 생성
TreeNode* buildHuffmanTree(char characters[], int frequencies[], int size) {
    int i;
    TreeNode* node, * x;
    HeapType* heap = create();
    element e, e1, e2;

    init(heap);
    for (i = 0; i < size; i++) {
        node = (TreeNode*)malloc(sizeof(TreeNode));
        node->ch = characters[i];
        node->weight = frequencies[i];
        node->left = node->right = NULL;
        e.ch = node->ch;
        e.key = node->weight;
        e.ptree = node;
        insert_min_heap(heap, e);


        for (int j = 1; j <= heap->heap_size; j++) {
            printf("%d ", heap->heap[j].key);
        }
        printf("\n");
    }

    for (i = 1; i < size; i++) {
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight;
        e.ptree = x;

        printf("/// %d + %d -> %d\n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);


        for (int j = 1; j <= heap->heap_size; j++) {
            printf("%d ", heap->heap[j].key);
        }
        printf("\n");
    }

    e = delete_min_heap(heap); 
    free(heap);
    return e.ptree; 
}

//허프만 코드 생성
void GenerateHuffmanCodes(char characters[], int frequencies[], int size) {
    TreeNode* root = buildHuffmanTree(characters, frequencies, size);
    int* arr = (int*)malloc(size * sizeof(int)); 
    int top = 0;
    print_codes(root, arr, top);
    free(arr); 
}
