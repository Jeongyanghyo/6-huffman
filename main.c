#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

main() {
	char characters[] = { 'a', 'e', 'i', 'o', 'u', 's', 't'};
	int frequencies[] = { 10, 15, 12, 3, 4, 13, 1 };
	int size = sizeof(characters) / sizeof(characters[0]);

	GenerateHuffmanCodes(characters, frequencies, size);

	return 0;
}