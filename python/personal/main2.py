import math


def radians_to_degrees():
    angle_r = float(input("Input an angle in radians: "))
    print(
        "Your angle in degrees is: ",
        round(angle_r * (180 / math.pi), 2),
        "\N{DEGREE SIGN}",
        sep="",
    )


def list_sort(list, order):
    if order == "asc":
        list.sort()
        print(list)
    else:
        if order == "desc":
            list.sort(reverse=True)
            print(list)
        else:
            print(list)


def decimal_to_binary():
    n_bin = 0
    putere = 10
    n_dec = int(input())
    while n_dec >= 1:
        n_bin *= 10
        if 2**putere <= n_dec:
            n_bin = n_bin + 1
            n_dec -= 2**putere
        putere -= 1
    n_bin *= 10 ** (putere + 1)
    print(n_bin)


def number_of_vowels():
    count = 0
    string = input()
    for caracter in string:
        if caracter in "aeiou":
            count += 1
    print(count)


def credit_card_number_hide():
    number = int(input())
    print(number % 10000)


def xes_equal_to_os():
    string = input()
    if string.count("X") + string.count("x") == string.count("O") + string.count("o"):
        print("True")
    else:
        print("False")


def discount():
    price = int(input())
    discount_percentage = int(input())
    discounted_price = price - price * discount_percentage / 100
    print(discounted_price)


def return_integers():  # de terminata
    int_string = 0
    string = input()
    for caracter in string:
        if isinstance(caracter, int):
            int_string = int_string * 10 + int(caracter)
    print(int_string)


def repeat_characters():
    cuvant_nou = ""
    string = input()
    for caracter in string:
        cuvant_nou = cuvant_nou + caracter + caracter
    print(cuvant_nou)


if __name__ == "__main__":
    # radians_to_degrees()
    # numere = [1, 2, 4, 6, 3, 7, 3, 1, 9, 0]
    # list_sort(numere, "asc")
    # decimal_to_binary()
    # number_of_vowels()
    # credit_card_number_hide()
    # xes_equal_to_os()
    # discount()
    # return_integers() #de terminat
    repeat_characters()
