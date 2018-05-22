class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        result = []
        elements = path.split('/')
        for element in elements:
            if element == '' or element == '.': 
                continue      
            if element == '..':
                if result:
                    result.pop()
            else:
                result.append(element)
        
        return '/' + '/'.join(result)

