#include <stdlib.h>
#include <string.h>

typedef struct {
    char **key;
    char **val;
    int *timestamp;
    int size;
    int capacity;
} TimeMap;

TimeMap* timeMapCreate() {
    TimeMap *obj = malloc(sizeof(TimeMap));
    obj->capacity = 1;
    obj->size = 0;
    obj->key = malloc(sizeof(char *) * obj->capacity);
    obj->val = malloc(sizeof(char *) * obj->capacity);
    obj->timestamp = malloc(sizeof(int) * obj->capacity);
    return obj;
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->key = realloc(obj->key, sizeof(char *) * obj->capacity);
        obj->val = realloc(obj->val, sizeof(char *) * obj->capacity);
        obj->timestamp = realloc(obj->timestamp, sizeof(int) * obj->capacity);
    }
    obj->key[obj->size] = strdup(key);
    obj->val[obj->size] = strdup(value);
    obj->timestamp[obj->size] = timestamp;   
    obj->size++;
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
    for (int i = obj->size - 1; i >= 0; i--) {
        if (obj->timestamp[i] <= timestamp && strcmp(obj->key[i], key) == 0)
            return obj->val[i];
    }
    return "";
}

void timeMapFree(TimeMap* obj) {
    for (int i = 0;i < obj->size; i++) {
        free(obj->key[i]);
        free(obj->val[i]);
    }
    free(obj->key);
    free(obj->val);
    free(obj->timestamp);
    free(obj);
}
#include <stdio.h>

int main(void)
{
    TimeMap *obj = timeMapCreate();

    timeMapSet(obj, "foo", "bar", 1);
    timeMapSet(obj, "foo", "bar2", 4);

    printf("get(foo, 1) = %s\n", timeMapGet(obj, "foo", 1));
    printf("get(foo, 3) = %s\n", timeMapGet(obj, "foo", 3));
    printf("get(foo, 4) = %s\n", timeMapGet(obj, "foo", 4));
    printf("get(foo, 5) = %s\n", timeMapGet(obj, "foo", 5));
    printf("get(foo, 0) = %s\n", timeMapGet(obj, "foo", 0));

    timeMapFree(obj);

    return 0;
}
