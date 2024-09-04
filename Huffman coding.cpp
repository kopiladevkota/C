
#include <stdio.h>
#include <stdlib.h>
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};
struct MinHeapNode* new_node(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}
struct MinHeap* create_min_heap(unsigned capacity) {
    struct MinHeap* min_heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (struct MinHeapNode**) malloc(min_heap->capacity * sizeof(struct MinHeapNode*));
    return min_heap;
}
void swap_min_heap_node(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
void min_heapify(struct MinHeap* min_heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq)
        smallest = left;

    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap_min_heap_node(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}
int is_size_one(struct MinHeap* min_heap) {
    return (min_heap->size == 1);
}
struct MinHeapNode* extract_min(struct MinHeap* min_heap) {
    struct MinHeapNode* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}
void insert_min_heap(struct MinHeap* min_heap, struct MinHeapNode* min_heap_node) {
    ++min_heap->size;
    int i = min_heap->size - 1;
    while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->array[i] = min_heap_node;
}
void build_min_heap(struct MinHeap* min_heap) {
    int n = min_heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        min_heapify(min_heap, i);
}
int is_leaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}
struct MinHeap* create_and_build_min_heap(char data[], int freq[], int size) {
    struct MinHeap* min_heap = create_min_heap(size);
    for (int i = 0; i < size; ++i)
        min_heap->array[i] = new_node(data[i], freq[i]);
    min_heap->size = size;
    build_min_heap(min_heap);
    return min_heap;
}
struct MinHeapNode* build_huffman_tree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* min_heap = create_and_build_min_heap(data, freq, size);
    while (!is_size_one(min_heap)) {
        left = extract_min(min_heap);
        right = extract_min(min_heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(min_heap, top);
    }
    return extract_min(min_heap);}
void print_codes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1); }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1); }
    if (is_leaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");  }}
void huffman_codes(char data[], int freq[], int size) {
    struct MinHeapNode* root = build_huffman_tree(data, freq, size);
    int arr[100], top = 0;
    print_codes(root, arr, top);}
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    huffman_codes(arr, freq, size);
    return 0;
}