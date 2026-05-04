#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

// Simple hash table implementation using arrays
typedef struct {
    long long key;
    long long count;
} HashNode;

HashNode hash[MAXN * 2];
int hashSize = 0;

// Function to find index of key in hash
int find(long long key) {
    for (int i = 0; i < hashSize; i++) {
        if (hash[i].key == key)
            return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    // Insert prefix sum 0 initially
    hash[hashSize].key = 0;
    hash[hashSize].count = 1;
    hashSize++;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = find(prefixSum);

        if (index != -1) {
            count += hash[index].count;
            hash[index].count++;
        } else {
            hash[hashSize].key = prefixSum;
            hash[hashSize].count = 1;
            hashSize++;
        }
    }

    printf("%lld\n", count);

    return 0;
}