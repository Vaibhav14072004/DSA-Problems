# Approach 2 

class Solution(object):
    def isValid(self,s):
        n= len(s)
        stack= []

        for x in s:
            if x== '(' or x== '{' or x== '[':
                stack.append(x)
            
            else:
                if len(stack)== 0: return False
                else:
                    if x== ')' and stack[-1]== '(': stack.pop()
                    elif x== '}' and stack[-1]== '{': stack.pop()
                    elif x== ']' and stack[-1]== '[': stack.pop()
                    else: return False

        return len(stack)== 0




# Approach 1 

"""
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
                
"""