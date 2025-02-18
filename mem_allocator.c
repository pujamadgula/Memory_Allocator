#include <unistd.h> //Required for sbrk()
#include <stdio.h> //For printf()


// Header Struct 
typedef struct header {
    // 1. Store size of allocated block 
    size_t size;
    // 2. Flag to evaluate whether the block is free (1) or in use (0)
    unsigned is_free; 
    // 3. pointer for next block in the list 
    struct header *next;
} header_t;


// Modify malloc with header data *****

void *malloc(size_t size) {
    size_t total_size;
    void *block;
    header_t *header;

    if (!size) return NULL;

    block = sbrk(size); //Expands the heap to 'size' bytes
    if (block == (void*) -1){
        return NULL; //sbrk() failed == no available memory for allocation
    }
    return block; //Return the newly allocated memory 
}

// Function to free the memory 


int main() {
    int *ptr = (int *) malloc(sizeof(int) *5); // Allocating memory for 5 integers
    if (ptr) { // check if the allocation was successful 
        ptr[0] = 10;  // Assign value (ex. 10) to first element
        printf("Allocated memory and set first element to %d\n", ptr[0]);
    }
    return 0;
}