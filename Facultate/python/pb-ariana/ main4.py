def divisors(number):
    div_list = [1, number]
    for div in range(2, number // 2 + 1):
        if number % div == 0:
            div_list.extend([div])
    div_list.sort()
    return div_list


def prime(n):
    if [1, n] == divisors(n):
        return True
    return False


def fibonacci(i):
    f1, f2 = 1, 1
    print(1, 1, sep="\n")
    for index in range(3, i + 1):
        f3 = f1 + f2
        f1 = f2
        f2 = f3
        print(f3)


def zile_pana_la_craciun(cm, cd):
    zile = 0
    luna = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if cm == 12 and cd == 25:
        zile = 0
    else:
        if cm == 12 and cd > 25:
            zile = 365 - (25 - cd) - 1
        else:
            for i in range(cm - 1, 12):
                zile += luna[i]
            zile = zile - cd - 5
    print(zile)


def palindrom(cuvant):
    if cuvant == cuvant[::-1]:
        print(True)
    else:
        print(False)


def rotate_list(list1, n):
    listanoua = list1[n::] + list1[:n:]
    print(listanoua)


def twin_primes(n):
    c = 0
    x = 3
    while c < n:
        if prime(x) and prime(x + 2):
            print(x, x + 2)
            c += 1
        x += 1


def prime_factors(n):
    for i in range(2, n):
        if n % i == 0:
            p = 0
            while n % i == 0:
                n /= i
                p += 1
            print(i, "^", p, sep="")


if __name__ == "__main__":
    fibonacci(i=int(input()))
    zile_pana_la_craciun(cm=int(input()), cd=int(input()))
    palindrom(cuvant=input())
    list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    list2 = [1, 2, 3]
    rotate_list(list1, n=int(input()))
    twin_primes(n=int(input()))
    prime_factors(n=int(input()))
