tests=[None]*10
count = int(input("How many numbers? "))

if(count>10): count=10

for i in range (0,count):
    test = int(input("Please type a number: "))
    tests[i]=test