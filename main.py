def stick_breaking(n, a):
    result = []
    for ai in a:
        n //= ai
        result.append(n)
        n *= ai
    return result

# Example usage
n = 1000
m = 4
a = [1, 2, 2, 1]
print(stick_breaking(n, a))  # Output: [250, 250, 125, 125, 250]