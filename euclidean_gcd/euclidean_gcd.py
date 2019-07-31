
def gcd(a ,b): # Euclidean Algorithm
    while a%b != 0:
        new_a = b
        new_b = a%b
        a = new_a
        b = new_b
    return b

def main():
    print(gcd(25623,23232525))

if __name__ == "__main__":
    main()