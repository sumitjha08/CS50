def main():
    height = get_height()
    pyramid(height)


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                return n
        except ValueError:
            pass


def pyramid(h):
    for i in range(1, h + 1):
        print(" " * (h - i) + "#" * i)


main()
