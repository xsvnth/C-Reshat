/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   10-Nov-2025                                                                      *
*  Exercise: Dynamic Bookshelf                                                              *
*  Description:                                                                             *
*       Simulates a bookshelf with multiple shelves. Supports adding books with pages,      *
*       querying the number of books on a shelf, and querying the number of pages in a book.*
*  Input:                                                                                   *
*       - Number of shelves                                                                 *
*       - Number of queries                                                                 *
*       - Queries of 3 types:                                                               *
*           1 x y : Add a book with y pages to shelf x                                      *
*           2 x y : Print pages of the y-th book on shelf x                                 *
*           3 x   : Print number of books on shelf x                                        *
*  Output:                                                                                  *
*       - Results of type 2 and type 3 queries                                              *
********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int* total_number_of_books;
int** total_number_of_pages;

int* capacity_of_shelf;
int main() {
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
    capacity_of_shelf = malloc(total_number_of_shelves * sizeof(int));
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int*));

    for (int i = 0; i < total_number_of_shelves; i++) {
        capacity_of_shelf[i] = 1;
        total_number_of_pages[i] = malloc(capacity_of_shelf[i] * sizeof(int));
    }

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (total_number_of_books[x] == capacity_of_shelf[x]) {
                capacity_of_shelf[x] *= 2;
                total_number_of_pages[x] = realloc(total_number_of_pages[x], capacity_of_shelf[x] * sizeof(int));
            }

            total_number_of_pages[x][total_number_of_books[x]++] = y;
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
