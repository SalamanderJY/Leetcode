int* grayCode(int n, int* returnSize)
{
    int *res = malloc(sizeof(int) * pow(2, n));
    *returnSize = pow(2, n);
    memset(res, 0, sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        res[i] = i ^ (i >> 1);
    }
    return res;
}