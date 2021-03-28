int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    *returnSize = digitsSize;
    int *res;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            res = (int *)malloc(sizeof(int) * (*returnSize));
            break;
        }
        if (i == digitsSize - 1) {
            (*returnSize)++;
            res = (int *)malloc(sizeof(int) * (*returnSize));
            res[0] = 1;
        }
    }
    int carry = 0;
    for (int i = (*returnSize) - 1, j = digitsSize - 1; i >= 0 && j >= 0; i--, j--) {
        int sum;
        if (j == digitsSize - 1)
            sum = digits[j] + 1;
        else
            sum = digits[j] + carry;
        carry = sum / 10;
        res[i] = sum % 10;
    }
    return res;
}