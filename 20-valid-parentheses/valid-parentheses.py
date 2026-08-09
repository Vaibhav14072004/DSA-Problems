class Solution(object):
    def isValid(self, s):
        n= len(s)
        stack= []

        if len(s)== 1: return False

        for x in s:
            if x== '{' or x== '(' or x== '[':
                stack.append(x)

            elif x== '}':
                if len(stack) > 0 and stack[-1]== '{':
                    stack.pop()
                else:
                    return False
                    break
            
            elif x== ')':
                if len(stack) > 0 and stack[-1]== '(':
                    stack.pop()
                
                else:
                    return False
                    break
            
            elif x== ']':
                if len(stack) > 0 and stack[-1]== '[':
                    stack.pop()
                
                else:

                    return False
                    break
            
        return len(stack)== 0
                
        