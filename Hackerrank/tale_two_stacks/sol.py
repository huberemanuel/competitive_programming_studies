# ref: https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues

class MyQueue(object):
    def __init__(self):
        self.Q = []
    
    def peek(self):
        if self.Q:
            return self.Q[-1]
        
    def pop(self):
        return self.Q.pop(-1)
        
    def put(self, value):
        self.Q.insert(0, value)

