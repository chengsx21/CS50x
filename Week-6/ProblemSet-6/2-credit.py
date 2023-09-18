from cs50 import get_int

card = get_int("Number: ")
while card <= 0:
    card = get_int("Number: ")

flag = False
length = 0
checksum = 0

while True:
    last = card % 10
    if flag:
        last *= 2
        if last > 9:
            last -= 9
    # Don't use '/' but '//'
    card = card // 10
    if card >= 10 and card <= 99:
        header = card
    checksum += last
    length += 1
    flag = not flag
    print(flag)
    if card == 0:
        break

if checksum % 10 != 0:
    print("INVALID\n")
elif (header == 34 or header == 37) and length == 15:
    print("AMEX\n")
elif header >= 51 and header <= 55 and length == 16:
    print("MASTERCARD\n")
elif header >= 40 and header <= 49 and (length == 13 or length == 16):
    print("VISA\n")
else:
    print("INVALID\n")
