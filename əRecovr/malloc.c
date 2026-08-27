#include <unistd.h>
#include <stddef.h>

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

static Block *head = NULL;

void *my_malloc(size_t size)
{
    if (size == 0)
        return NULL;

    Block *current = head;

    // Look for a free block we can reuse
    while (current) {
        if (current->free && current->size >= size) {
            current->free = 0;
            return (void *)(current + 1);
        }

        current = current->next;
    }

    // No suitable block → request more memory
    Block *block = sbrk(sizeof(Block) + size);

    if (block == (void *)-1)
        return NULL;

    block->size = size;
    block->free = 0;
    block->next = head;

    head = block;

    return (void *)(block + 1);
}

void my_free(void *ptr)
{
    if (ptr == NULL)
        return;

    Block *block = (Block *)ptr - 1;
    block->free = 1;
}
#include <stdio.h>

int main(void)
{
    int *p = my_malloc(5 * sizeof(int));

    if (p == NULL)
        return 1;

    for (int i = 0; i < 5; i++)
        p[i] = (i + 1) * 10;

    for (int i = 0; i < 5; i++)
        printf("%d ", p[i]);

    printf("\n");

    my_free(p);

    // Test that freed memory gets reused
    int *q = my_malloc(5 * sizeof(int));

    printf("p = %p\n", (void *)p);
    printf("q = %p\n", (void *)q);

    my_free(q);

    return 0;
}
