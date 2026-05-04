#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table overflow\n");
}

void search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    scanf("%d", &m); 
    scanf("%d", &n);   

    int table[m];

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            search(table, m, key);
        }
    }

    return 0;
}