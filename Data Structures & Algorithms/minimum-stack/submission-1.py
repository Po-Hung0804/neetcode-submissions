class MinStack:

    def __init__(self):
        self.stack=[]
        self.min_v=float('inf')

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append(0)
            self.min_v=val
        else:
            self.stack.append(val-self.min_v)
            if val<self.min_v:
                self.min_v=val

    def pop(self) -> None:
        if not self.stack:
            return 
        p=self.stack.pop()
        # pop the smallest element in stack
        if p<0:
            self.min_v=self.min_v-p

    def top(self) -> int:
        top=self.stack[-1]
        if top>0:
            return top+self.min_v
        else:
            return self.min_v

    def getMin(self) -> int:
        return self.min_v
