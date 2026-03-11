def main():
    cents = get_cents()
    coins = calculate_coins(cents)
    print(coins)


def get_cents():
    while True:
        try:
            cents = float(input("Change owed: "))
            if cents >= 0:
                return round(cents * 100)
        except ValueError:
            pass


def calculate_coins(cents):
    coins = 0

    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin

    return coins


main()
