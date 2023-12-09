t = int(input())

for _ in range(t):
    n, k, b, s = map(int, input().split())

    min_sum = n * k
    if s < min_sum or (s - min_sum) > b:
        print(-1)
        continue

    rem_sum = s - min_sum
    add_elements = b - rem_sum
    if add_elements > n:
        print(-1)
        continue

    elem_value = add_elements // n
    rem_elements = add_elements % n

    a = [elem_value] * n
    for i in range(rem_elements):
        a[i] += 1

    print(*a)

