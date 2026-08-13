/********************************************************************************************
*  Author: @7meTh                                                                           *
*  Date:   25-Nov-2025                                                                      *
*  Program: Postal Town System                                                              *
*  Description:                                                                             *
*       Simulates a postal system in multiple towns.                                        *
*       Each town contains multiple post offices, which hold packages.                      *
*       Supports operations to:                                                             *
*           - Print all packages in a town                                                  *
*           - Send acceptable packages from one office to another                           *
*           - Find the town with the most packages                                          *
*           - Find a town by its name                                                       *
*  Structures:                                                                              *
*       - package: Represents a package with an ID and weight                               *
*       - post_office: Represents a post office with weight limits and packages             *
*       - town: Represents a town with a name and multiple post offices                     *
*  Input:                                                                                   *
*       - Number of towns                                                                   *
*       - Town names, number of offices, office details, packages details                   *
*       - Number of queries                                                                 *
*       - Queries of 3 types:                                                               *
*           1 town_name : Print all packages in the town                                    *
*           2 source_name src_idx target_name tgt_idx : Send acceptable packages            *
*           3 : Print the town with the most packages                                       *
*  Output:                                                                                  *
*       - Results printed according to query type                                           *
********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

// --- Struct definitions ---
struct package {
    char* id;
    int weight;
};
typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};
typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};
typedef struct town town;

// --- Function declarations ---
void print_all_packages(town t);
void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index);
town town_with_most_packages(town* towns, int towns_count);
town* find_town(town* towns, int towns_count, char* name);

// --- Function implementations ---

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office* src = &source->offices[source_office_index];
    post_office* tgt = &target->offices[target_office_index];

    int idx = tgt->packages_count;
    // Count how many packages will be added
    for (int i = 0; i < src->packages_count; i++) {
        if (src->packages[i].weight >= tgt->min_weight && src->packages[i].weight <= tgt->max_weight)
            idx++;
    }

    tgt->packages = realloc(tgt->packages, sizeof(package) * idx);
    int target_idx = tgt->packages_count;

    for (int i = 0; i < src->packages_count; i++) {
        if (src->packages[i].weight >= tgt->min_weight && src->packages[i].weight <= tgt->max_weight) {
            tgt->packages[target_idx] = src->packages[i];
            target_idx++;
            // Remove package from source by shifting left
            for (int k = i; k < src->packages_count - 1; k++)
                src->packages[k] = src->packages[k + 1];
            src->packages_count--;
            i--; // adjust index after removal
        }
    }
    tgt->packages_count = target_idx; // update target count correctly
}

town town_with_most_packages(town* towns, int towns_count) {
    int max_packages = -1;
    int max_index = 0;
    for (int i = 0; i < towns_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++)
            total += towns[i].offices[j].packages_count;
        if (total > max_packages) {
            max_packages = total;
            max_index = i;
        }
    }
    return towns[max_index];
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++)
        if (strcmp(towns[i].name, name) == 0)
            return &towns[i];
    return NULL;
}

// --- Main function ---
int main() {
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town) * towns_count);

    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);

        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count,
                             &towns[i].offices[j].min_weight,
                             &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);

            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];

    while (queries--) {
        int type;
        scanf("%d", &type);

        switch (type) {
        case 1:
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
            break;
        case 2: {
            scanf("%s", town_name);
            town* source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);

            scanf("%s", town_name);
            town* target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);

            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        }
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }

    return 0;
}

