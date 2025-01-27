nums = [1, 2, 3, 2, 3, 4, 4, 4, 5, 4, 5, 6]

m = sum(nums) / len(nums)

sorted_nums = sorted(nums)
n = len(sorted_nums)
med = (sorted_nums[n//2] + sorted_nums[(n-1)//2]) / 2

freq = {}
for num in nums:
    freq[num] = freq.get(num, 0) + 1

mod = max(freq, key=freq.get)

print(f"Mean: {m}")
print(f"Median: {med}")
print(f"Mode: {mod}")
