import numpy as np

def least_square_fitting(p: list, c: list):
    pi = []
    b = [0] * 3
    for power in range(0, 5):
        pi.append(pi_calc(p, power))

    # Calculating b matrix element
    for i in range(0, len(c)):
        b[0] += c[i]
        b[1] += c[i] * p[i]
        b[2] += c[i] * p[i] ** 2
    A_mat = np.array([[pi[0], pi[1], pi[2]],
                      [pi[1], pi[2], pi[3]],
                      [pi[2], pi[3], pi[4]]])
    b_mat = np.array(b)
    print(np.matmul(np.linalg.inv(A_mat), b_mat))


def pi_calc(p: list, power):
    tmp = 0
    for i in range(0, len(p)):
        tmp += p[i]**power

    return tmp

if __name__ == '__main__':
    p = [70, 75, 110, 150]
    c = [75000, 80000, 110000, 150000]
    least_square_fitting(p, c)
