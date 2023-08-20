#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD, SUB, MUL, DIV, FIB
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *makeNode(TypeTag type, int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int calc(Node *node) {
    if (node == NULL) return 0;
    switch (node->type) {
        case ADD:
            return calc(node->left) + calc(node->right);
        case SUB:
            return calc(node->left) - calc(node->right);
        case MUL:
            return calc(node->left) * calc(node->right);
        case DIV:
            return calc(node->left) / calc(node->right);
        case FIB:
            
            int n = node->value;
            if (n <= 0) return 0;
            if (n == 1 || n == 2) return 1;
            int *dp = (int *)malloc((n + 1) * sizeof(int));
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            int result = dp[n];
            free(dp);
            return result;
        default:
            return 0;
    }
}

int main() {
    Node *add = makeNode(ADD, 0, makeNode(FIB, 10, NULL, NULL), makeNode(FIB, 6, NULL, NULL));
    Node *mul = makeNode(MUL, 0, makeNode(FIB, 5, NULL, NULL), makeNode(FIB, 4, NULL, NULL));
    Node *sub = makeNode(SUB, 0, mul, add);
    Node *fib = makeNode(FIB, 10, NULL, NULL); // Change to 10 directly
    printf("add: %d\n", calc(add));
    printf("mul: %d\n", calc(mul));
    printf("sub: %d\n", calc(sub));
    printf("fib: %d\n", calc(fib));
    
    // Clean up memory
    free(add);
    free(mul);
    free(sub);
    free(fib);
    
    return 0;
}
