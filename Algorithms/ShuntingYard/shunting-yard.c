/**
 * @author Nhat Minh Nguyen
 * @date   21-05-18
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define bool         int
#define true         1
#define false        0

#define MAX_INPUT_LENGTH  1000
#define MAX_NUM_TOKENS    300
#define QUEUE_CAP         300
#define STACK_CAP         300


#define ADD             -1
#define SUBTRACT        -2
#define MULTIPLY        -3
#define DIVIDE          -4
#define LEFT_BRACKET    -5
#define RIGHT_BRACKET   -6


char input[MAX_INPUT_LENGTH];
float tokens[MAX_NUM_TOKENS];
int num_tokens = 0;


/**
 *  Data structure: Queue
 *  Functions:
 *    init_queue       initialize the queue
 *    queue_is_empty   check if the queue is empty
 *    enqueue          add an element to the end (tail) of the queue
 *    dequeue          return the element at the start (head) of the queue and
 *                         remove it from the queue
**/


struct Queue {
    int head;
    int tail;
    float key[QUEUE_CAP];
} queue;


void init_queue() {
    queue.head = 0;
    queue.tail = -1;
}


bool queue_is_empty() {
    if (queue.head > queue.tail) {
        return true;
    }
    return false;
}


void enqueue(float f) {
    queue.tail++;
    queue.key[queue.tail] = f;
}


float dequeue() {
    float result = queue.key[queue.head];
    queue.head++;
    return result;
}


/**
 *  Data structure: Stack
 *  Functions:
 *    init_stack       initialize the stack
 *    stack_is_empty   check if the stack is empty
 *    push_stack       add an element to the top of the stack
 *    top_stack        return the element at the top of the stack
 *    pop_stack        return the element at the top of the stack and
 *                        remove it from the stack
**/

struct Stack {
    int size;
    float key[STACK_CAP];
} stack;


void init_stack() {
    stack.size = 0;
}


bool stack_is_empty() {
    if (stack.size == 0) {
        return true;
    }
    else {
        return false;
    }
}


float top_stack() {
    return stack.key[stack.size - 1];
}


void push_stack(float f) {
    stack.key[stack.size] = f;
    stack.size++;
}


float pop_stack() {
    float result = stack.key[stack.size - 1];
    stack.size--;
    return result;
}


bool is_operator_char(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c== ')') {
        return true;
    }
    return false;
}


bool is_operator_token(float token) {
    if (token < 0) {
        return true;
    }
    return false;
}


float to_operator_token(char c) {
    if (c == '+') {
        return ADD;
    }
    if (c == '-') {
        return SUBTRACT;
    }
    if (c == '*') {
        return MULTIPLY;
    }
    if (c == '/') {
        return DIVIDE;
    }
    if (c == '(') {
        return LEFT_BRACKET;
    }
    return RIGHT_BRACKET;
}


char to_operator_char(float token) {
    if (token == ADD) {
        return '+';
    }
    if (token == SUBTRACT) {
        return '-';
    }
    if (token == MULTIPLY) {
        return '*';
    }
    if (token == DIVIDE) {
        return '/';
    }
    if (token == LEFT_BRACKET) {
        return '(';
    }
    return ')';
}


void tokenize() {
    char buf[12];
    int  buf_size = 0;
    num_tokens = 0;

    // Tokenize the input
    for (int i = 0; i < (int) strlen(input); i++) {
        if (is_operator_char(input[i])) {
            if (i == 0) {
                tokens[num_tokens] = to_operator_token(input[i]);
                num_tokens++;
            }
            else {
                if (is_operator_char(input[i - 1])) {
                    tokens[num_tokens] = to_operator_token(input[i]);
                    num_tokens++;
                }
                else {
                    buf[buf_size] = '\0';
                    tokens[num_tokens] = (float) atof(buf);
                    tokens[num_tokens + 1] = to_operator_token(input[i]);
                    buf_size = 0;
                    num_tokens += 2;
                }
            }
        }
        else {
            buf[buf_size] = input[i];
            buf_size++;
        }
    }

    // Check if there is still a number the buffer
    if (buf_size > 0) {
        buf[buf_size] = '\0';
        tokens[num_tokens] = (float) atof(buf);
        num_tokens++;
    }
}


void print_tokens() {
    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        if (is_operator_token(tokens[i])) {
            printf("Token[%d]: %c\n", i, to_operator_char(tokens[i]));
        }
        else {
            printf("Token[%d]: %f\n", i, tokens[i]);
        }
    }
    printf("\n");
}


int precedence(float operator) {
    if (operator == LEFT_BRACKET || operator == RIGHT_BRACKET) {
        return 2;
    }
    else if (operator == MULTIPLY || operator == DIVIDE) {
        return 1;
    }
    return 0;
}


void shunting_yard() {
    init_queue();
    init_stack();

    for (int i = 0; i < num_tokens; i++) {
        float token = tokens[i];
        if (!is_operator_token(token)) {
            enqueue(token);
        }
        else if (token == LEFT_BRACKET) {
            push_stack(token);
        }
        else if (token == RIGHT_BRACKET) {
            while (top_stack() != LEFT_BRACKET) {
                enqueue(pop_stack());
            }
            pop_stack();
        }
        else {
            while (!stack_is_empty() && top_stack() != LEFT_BRACKET && precedence(top_stack()) >= precedence(token)) {
                enqueue(pop_stack());
            }
            push_stack(token);
        }
    }

    while (!stack_is_empty()) {
        enqueue(pop_stack());
    }
}


void print_postfix() {
    printf("Postfix expression: \n");
    for (int i = queue.head; i <= queue.tail; i++) {
        if (is_operator_token(queue.key[i])) {
            printf("%c ", to_operator_char(queue.key[i]));
        }
        else {
            printf("%.4f ", queue.key[i]);
        }
    }
    printf("\n");
}


float calc(float operand_1, float operator, float operand_2) {
    if (operator == ADD) {
        return (operand_1 + operand_2);
    }
    if (operator == SUBTRACT) {
        return (operand_1 - operand_2);
    }
    if (operator == MULTIPLY) {
        return (operand_1 * operand_2);
    }
    return (operand_1 / operand_2);
}


float evaluate() {
    init_stack();

    while (!queue_is_empty()) {
        float token = dequeue();
        if (!is_operator_token(token)) {
            push_stack(token);
        }
        else {
            float operand_2 = pop_stack();
            float operand_1 = pop_stack();
            float result = calc(operand_1, token, operand_2);
            push_stack(result);
        }
    }
    return pop_stack();
}


int main() {
    printf("Input: ");
    if (scanf("%s", input)) {
        tokenize();
        // print_tokens();

        shunting_yard();
        print_postfix();

        float result = evaluate();
        printf("Result: %.4f\n", result);
    }
    return 0;
}
