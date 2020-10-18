import random


random.seed(42)


with open("add.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 100)
        second = random.randint(-100, 100) ** random.randint(1, 100)

        res = first + second
        f.write(f"{first} {second} {res}\n")


with open("sub.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 100)
        second = random.randint(-100, 100) ** random.randint(1, 100)

        res = first - second
        f.write(f"{first} {second} {res}\n")


with open("mul.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 100)
        second = random.randint(-100, 100) ** random.randint(1, 100)

        res = first * second
        f.write(f"{first} {second} {res}\n")


with open("div.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 10)
        second = int((random.randint(-100, 100) ** random.randint(1, 10)) / (i + 1))
        second = 1 if second == 0 else second

        res = int(first / second)
        f.write(f"{first} {second} {res}\n")


with open("less.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 100)
        second = random.randint(-100, 100) ** random.randint(1, 100)

        res = int(first < second)
        f.write(f"{first} {second} {res}\n")


with open("greater.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 100)
        second = random.randint(-100, 100) ** random.randint(1, 100)

        res = int(first > second)
        f.write(f"{first} {second} {res}\n")

with open("equal.txt", "w") as f:
    for i in range(100):
        first = random.randint(-100, 100) ** random.randint(1, 100)
        second = first if random.choice([True, False]) else  random.randint(-100, 100) ** random.randint(1, 100)

        res = int(first ==  second)
        f.write(f"{first} {second} {res}\n")
