#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3 // Maximum keys in a node (t-1 where t is the minimum degree)
#define MIN_KEYS 1 // Minimum keys in a node (ceil(t/2) - 1)
#define MAX_CHILDREN (MAX_KEYS + 1) // Maximum children in a node (t)

typedef struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode* children[MAX_CHILDREN];
    int numKeys;
    int isLeaf;
} BTreeNode;

// Create a new BTree node
BTreeNode* createNode(int isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Split the child node when it becomes full
void splitChild(BTreeNode* parent, int index, BTreeNode* child) {
    BTreeNode* newChild = createNode(child->isLeaf);
    newChild->numKeys = MIN_KEYS;

    // Move the second half of the keys to the new child
    for (int i = 0; i < MIN_KEYS; i++) {
        newChild->keys[i] = child->keys[i + MIN_KEYS + 1];
    }

    // If the child is not a leaf, move the second half of the children to the new child
    if (!child->isLeaf) {
        for (int i = 0; i < MIN_KEYS + 1; i++) {
            newChild->children[i] = child->children[i + MIN_KEYS + 1];
        }
    }

    // Update the number of keys in the original child
    child->numKeys = MIN_KEYS;

    // Move the children of the parent to make space for the new child
    for (int i = parent->numKeys; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }

    // Set the new child in the parent's children array
    parent->children[index + 1] = newChild;

    // Move the parent's keys to make space for the new key
    for (int i = parent->numKeys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }

    // Move the middle key from the child to the parent
    parent->keys[index] = child->keys[MIN_KEYS];
    parent->numKeys++;
}

// Insert a key into a non-full node
void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Find the position to insert the key
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find the child to insert into
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }

        i++;

        // If the child is full, split it
        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }

        // Recursively insert into the appropriate child
        insertNonFull(node->children[i], key);
    }
}

// Insert a key into the B-tree
void insert(BTreeNode** root, int key) {
    BTreeNode* r = *root;

    // If the root is full, create a new root and split the old root
    if (r->numKeys == MAX_KEYS) {
        BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = r;
        splitChild(newRoot, 0, r);
        int i = 0;
        if (newRoot->keys[0] < key) {
            i++;
        }
        insertNonFull(newRoot->children[i], key);
        *root = newRoot;
    } else {
        insertNonFull(r, key);
    }
}

// Traverse the B-tree and print the keys
void traverse(BTreeNode* root) {
    if (root == NULL) return;

    for (int i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }

    if (!root->isLeaf) {
        traverse(root->children[root->numKeys]);
    }
}

int main() {
    // Create a B-tree with minimum degree 2 (t = 2)
    BTreeNode* root = createNode(1); // root is a leaf node initially

    // Insert keys into the B-tree
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 10);
    insert(&root, 9);
    insert(&root, 1);
    insert(&root, 12);
    insert(&root, 11);
    insert(&root, 13);

    printf("Traversal of the constructed B-tree is:\n");
    traverse(root);

    return 0;
}