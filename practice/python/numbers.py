# ============================================================
# Practice: Numbers
# Summary: prime check, multiplication table, Euclidean GCD.
# Run:     python practice/python/numbers.py
# ============================================================

# ----- 1. Is a number prime? -----
def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


# ----- 2. Multiplication table for n, 1..limit -----
def multiplication_table(n, limit):
    rows = []
    for i in range(1, limit + 1):
        rows.append(f"{n} x {i} = {n * i}")
    return rows


# ----- 3. GCD via the Euclidean algorithm -----
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


if __name__ == "__main__":
    print(is_prime(7), is_prime(10))          # Output: True False
    for line in multiplication_table(7, 10):  # 7 x 1 = 7 ... 7 x 10 = 70
        print(line)
    print(gcd(48, 18))                        # Output: 6
