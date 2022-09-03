A, B = map(int, input().split())
q, r = A // B, A % B
if A != 0 and r < 0:
    q, r = q + 1, r - B
print(q)
print(r)
