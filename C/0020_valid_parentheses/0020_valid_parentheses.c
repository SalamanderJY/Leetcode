void push(char *stack, int *num, char element) {
    stack[*num] = element;
    (*num)++; 
}

char top(char *stack, int *num) {
    return stack[*num - 1];
}

void pop(char *stack, int *num) {
    (*num)--; 
}


bool isValid(char *s) {
    char stack[10000];
    int num = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(stack, &num, s[i]);
        }
        else {
            if (num == 0) {
                return false;
            }
            char stackTop = top(stack, &num);
            if ((stackTop == '[' && s[i] == ']') ||
                (stackTop == '(' && s[i] == ')') ||
                (stackTop == '{' && s[i] == '}')) {
                pop(stack, &num);
            }
            else {
                return false;
            }
        }
    }
    return num == 0;
}