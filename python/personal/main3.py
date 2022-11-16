import random


def less_than(list, number):
    list2 = []
    for element in list:
        if element <= number:
            list2.append(element)
    print(list2)


def divisors(number):
    div_list = [1, number]
    for div in range(2, number // 2 + 1):
        if number % div == 0:
            div_list.extend([div])
    div_list.sort()
    return div_list


def list_overlap(list1, list2):
    list_o = []
    for element in list1:
        if element in list2:
            list_o.append(element)
    print(list_o)


def generate_two_random_lists():
    l1 = random.randint(1, 20)
    l2 = random.randint(1, 20)
    for x in range(0, l1):
        list1.append(random.randint(0, 10))
    for x in range(0, l1):
        list2.append(random.randint(0, 10))
    print(list1)
    print(list2)


def guessing_game():
    guess = -1
    answer = random.randint(1, 9)
    while guess != "exit":
        guess = input("Take a guess: ")
        if int(guess) == answer:
            print("You are right!")
            break
        else:
            if int(guess) < answer:
                print("Try higher!")
            else:
                print("Try lower!")


def prime_number():
    n = int(input())
    if [1, n] == divisors(n):
        print(n, "is a prime number")
    else:
        print(n, "is not a prime number")


def my_function(sir1, s):
    c = 0
    sirnou = ""
    i = 0
    while(c < sir1.count(s) - 1):
        sirnou += sir1[i]
        if(sir1[i] == s):
            c += 1
        i += 1
    print(sirnou)
    
    
def prime_factors(n):
    for i in n/2:
        if n % i == 0:
            print(i)
            p = 0
            while n % i == 0:
                n /= i
                p += 1
            print("^", p)
    
    
    
if __name__ == "__main__":

    sir1 = "Py thon PyCharm py charm"
    sir2 = "Py"
    my_function(sir1, s = " ")

    # list1 =  [1,3,7,4,8,9,4,2,5,98,2,3,5,7,9,8,6,5,5,5664,634,6546,45,645,3,6,45,63,53,63]
    # list2 =  [514,52,46,3457,658,725,98,1634,631,5,1435,14,5,135,14,52,165,745,7878,0,1,23,123,234,5434,5]
    list1 = []
    list2 = []
    # less_than(list, number = int(input()))
    # divisors(number=int(input()))
    # generate_two_random_lists()
    # list_overlap(list1, list2)
    # guessing_game()
    # prime_number()
