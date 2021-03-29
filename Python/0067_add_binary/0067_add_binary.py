class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        len_a = len(a)
        len_b = len(b)
        carry = [0 for i in range(max(len_a, len_b) + 1)]
        result = ""
        # loop max(len_a, len_b) + 1 times.
        for i in range(max(len_a, len_b), -1, -1):
            len_a -= 1
            len_b -= 1
            param_a = int(a[len_a]) if len_a >= 0 else 0
            param_b = int(b[len_b]) if len_b >= 0 else 0
            if param_a + param_b + carry[i] > 1:
                carry[i - 1] = 1
                result = str(param_a + param_b + carry[i] - 2) + result
            else:
                carry[i - 1] = 0
                result = str(param_a + param_b + carry[i]) + result

        return result if result[0] != '0' else result[1:]

if __name__ == '__main__':
    solution = Solution()
    print(solution.addBinary("0", "0"))
