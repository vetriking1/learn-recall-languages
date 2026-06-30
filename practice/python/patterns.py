# ============================================================
# Practice: Patterns
# Summary: right-angled triangle, centered pyramid.
# Run:     python practice/python/patterns.py
# ============================================================

# ----- 1. Right-angled triangle of stars -----
def right_triangle(n):
    lines = []
    for i in range(1, n + 1):
        lines.append("*" * i)
    return lines


# ----- 2. Centered pyramid of stars (height h) -----
def pyramid(h):
    lines = []
    for i in range(1, h + 1):
        spaces = " " * (h - i)
        stars = "*" * (2 * i - 1)
        lines.append(spaces + stars)
    return lines


if __name__ == "__main__":
    print("Right triangle (N=5):")
    for line in right_triangle(5):
        print(line)
    # *
    # **
    # ***
    # ****
    # *****

    print("Pyramid (height=5):")
    for line in pyramid(5):
        print(line)
    #     *
    #    ***
    #   *****
    #  *******
    # *********
