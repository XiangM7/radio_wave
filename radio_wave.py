n, d = map(int, input().split())
a = list(map(int, input().split()))

# Coverage for each city
coverage = [0] * n  # To store coverage for each city
j = 0
for i in range(n):
    # Move the left pointer `j` to ensure a[j] >= a[i] - d
    while j < n and a[j] < a[i] - d:
        j += 1
    # Count cities in range [a[i] - d, a[i] + d]
    k = j
    while k < n and a[k] <= a[i] + d:
        coverage[i] += 1
        k += 1
    print(coverage[i])

# Maximum coverage for any tower
max_coverage = 0
j = 0
for i in range(n):
    # Move the left pointer `j` to ensure a[j] >= a[i] - d
    while j < n and a[j] < a[i] - d:
        j += 1
    # Update the maximum coverage with the current window size
    max_coverage = max(max_coverage, i - j + 1)

print(max_coverage)

