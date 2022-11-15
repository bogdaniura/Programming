def fibonacci():
    i = int(input())
    f1, f2 = 1, 1
    print(1, 1, sep="\n")
    for index in range(3, i + 1):
        f3 = f1 + f2
        f1 = f2
        f2 = f3
        print(f3)


def zile_pana_la_craciun():
    zile = 0
    luna = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31]
    cm = int(input())
    cd = int(input())
    if(cm == 12 and cd == 25):
        zile = 0
    else:
        if(cm == 12 and cd > 25):
            zile = 365 - (25 - cd) - 1
        else:
            for i in range(cm - 1, 12):
                zile += luna[i]
            zile = zile - cd - 5
    print(zile)


def palindrom():
    cuvant = input()
    if cuvant == cuvant[::-1]:
        print(True)
    else:
        print(False)


def alternative_list_merge(list1, list2): #de terminat
    list3 = []
    for i in range(len(list1) + len(list2)):
        if i % 2 == 0:
            list3.append(list1[int(i//2+0.5)])
        else:
            list3.append(list2[i//2])
    print(list3)


def rotate_list(list1, n):
    listanoua = list1[n::] + list1[:n:]
    print(listanoua)


def twin_primes(n):
    c = 0
    while c < n:
        
    


if __name__ == "__main__":
    # fibonacci()
    # zile_pana_la_craciun()
    # palindrom()
    # list1 = [1, 2, 3, 4, 5, 6, 7, 8 ,9, 10]
    # list2 = [1, 2, 3]
    # alternative_list_merge(list1, list2)
    # rotate_list(list1, 3)
    