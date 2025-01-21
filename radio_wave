def radio_tower_coverage():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n, d = int(data[0]), int(data[1])
    A = list(map(int, data[2:]))
    
    # Calculate coverage for each city
    coverage = []
    max_coverage = 0
    j = 0  # Pointer for left boundary of range
    
    for i in range(n):
        # Move the left pointer `j` such that A[j] >= A[i] - d
        while j < n and A[j] < A[i] - d:
            j += 1
        # Count cities in range
        count = 0
        k = j  # Temporary pointer to count cities within range
        while k < n and A[k] <= A[i] + d:
            count += 1
            k += 1
        coverage.append(count)
    
    # Calculate maximum coverage for any tower placement
    j = 0
    for i in range(n):
        # Move the left pointer `j` such that A[j] >= A[i] - d
        while j < n and A[j] < A[i] - d:
            j += 1
        # Update maximum coverage
        max_coverage = max(max_coverage, i - j + 1)
    
    # Print results
    for c in coverage:
        print(c)
    print(max_coverage)

