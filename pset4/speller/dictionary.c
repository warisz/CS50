// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;

    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];


    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        int i = hash(word);
        node *newVal = malloc(sizeof(node));

        if (newVal == NULL){
            unload();
            return false;
        }

        strcpy(newVal->word, word);
        newVal->next = NULL;

        /*
        for(int k=0; k<LENGTH; k++){
            if(word[k] == '\n'){
                newVal->word[k] = '\0';
                break;
            }
            newVal->word[k] = word[k];
        }
        newVal->next = NULL;
        */

        if(hashtable[i] == NULL){
            hashtable[i] = newVal;

        }else{
            newVal->next = hashtable[i];
            hashtable[i] = newVal;
        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int words = 0;

    for(int i=0; i<N; i++){
        node *cursor = hashtable[i];
        while(cursor != NULL){
            words++;
            cursor = cursor->next;
        }
    }

    return words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    node *cursor = hashtable[hash(word)];
    char *copy = malloc(strlen(word) + 1);
    strcpy(copy, word);

    for(int i = 0; copy[i]; i++){
        copy[i] = tolower(copy[i]);
    }
    while(cursor != NULL){
        if(strcmp(cursor->word, copy) == 0){
            free(copy);
            return true;
        }
        cursor = cursor->next;
    }

    free(copy);

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for(int i=0; i<N; i++){
        node *cursor = hashtable[i];

        while(cursor!=NULL){
            node *temp = cursor;
            cursor = cursor->next;
            hashtable[i] = cursor;
            free(temp);
        }
    }

    return true;

}
