def fibo(n):
    n = n + 1
    arr = [0]*n
    arr[0] = 0
    arr[1] = 1
    for i in range(2, n):
        arr[i] = arr[i-1] + arr[i-2]
    return arr[n-1]

def main():
    print(fibo(100))

if __name__ == "__main__":
    main()