class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack=[]
        for element in operations:
            if element=='D':
                stack.append(stack[-1]*2)
            elif element=='C':
                stack.pop()
            elif element=='+':
                stack.append(stack[-1]+stack[-2])
            else:
                stack.append(int(element))
        return sum(stack)