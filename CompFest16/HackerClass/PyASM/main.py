def check_password():
    pw = input('Enter THE password: ')

    if not pw.isalnum():
        print('Password format is not valid!')
        exit()

    if len(pw) > 9:
        print('Password is too long!')
        exit()

    if len(pw) < 9:
        print('Password is too short!')
        exit()

    x = [0, 0, 0, 0, 0, 0, 0, 0, 0]

    for i in range(9):
        x[len(x) - i - 1] = ord(pw[i])

    print(x)

    if x[7] + 69 != 120:
        print('Wrong password.')
        return None

    if x[3] ^ 1337 != 1355:
        print('Wrong password.')
        return None

    if x[0] // 22 != 5:
        print('Wrong password.')
        return None

    if x[4] - 16 != 35:
        print('Wrong password.')
        return None

    if x[8] << 3 != 832:
        print('Wrong password.')
        return None

    if x[1] ** 2 != 9409:
        print('Wrong password.')
        return None

    if x[6] * 7 != 693:
        print('Wrong password.')
        return None

    if ~x[2] != -110:
        print('Wrong password.')
        return None

    if x[5] != 107:
        print('Wrong password.')
        return None

    print("Correct! Here's your flag: ")
    with open('flag.txt', 'r') as f:
        print(f.read())

    exit()

check_password()
