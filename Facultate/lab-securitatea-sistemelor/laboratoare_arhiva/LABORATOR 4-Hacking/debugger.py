import pdb


def addition(a, b):
    answer = a + b
    return answer
 
 

x =int( input("Enter first number : "))
y = int(input("Enter second number : "))
def new_func(addition, x, y):
    sum = addition(x, y)
    print(sum)

pdb.set_trace()

new_func(addition, x, y)