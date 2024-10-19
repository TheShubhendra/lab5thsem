# # from error import *
# for i in range(10):
#     for j in range(5):
#         print("*",end="")
#     print()
# for i in range(1,5):
#     for j in range(i):
#         print(i,end=" ")
#     print()
# for i in range(4):
#     for j in range(1, i+2):
#         print(j,end=" ")
#     print()

# for i in range(1,5):
#     for j in range(4-i):
#         print("  ",end="")
#     for j in range(1,2*i):
#         print(j,end=" ")
#     print()

print(*[" "*2*(4-i)+(" ".join(list(map(str,range(1,2*i))))) for i in range(5)], sep="\n")