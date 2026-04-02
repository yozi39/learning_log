NAME = "周俊吉"
STUDENT_ID = "2522204236"

def generate_sequence(name, sid):
	A = []
	for ch in name:
		A.append(ord(ch))
	for ch in sid:
		# 将学号每一位字符转换为对应整数
		if ch.isdigit():
			A.append(int(ch))
		else:
			A.append(ord(ch))
	# 对序列中第 i 个元素（位置从1开始）执行变换：乘以 (i + len(STUDENT_ID)%100)
	len_mod = len(sid) % 100
	for i in range(1, len(A) + 1):
		multiplier = i + len_mod
		A[i-1] = A[i-1] * multiplier%100
	return A

def insertion_sort_stable(arr, key_func):
	# 原地稳定插入排序
	n = len(arr)
	for i in range(1, n):
		current = arr[i]
		j = i - 1
		while j >= 0 and key_func(arr[j]) > key_func(current):
			arr[j+1] = arr[j]
			j -= 1
		arr[j+1] = current

def sort_by_rules(A):
	# 绑定原始索引以便在相等时保持稳定性（不过插入排序本身已保持稳定）
	arr = [(idx, val) for idx, val in enumerate(A)]
	def key(item):
		val = item[1]
		parity = 0 if val % 2 == 1 else 1  # 奇数优先（0），偶数次之（1）
		return (parity, val)
	insertion_sort_stable(arr, key)
	return [item[1] for item in arr]

def main():
	A = generate_sequence(NAME, STUDENT_ID)
	B = sort_by_rules(A)
	# 输出：一行，元素以单个空格分隔，无其他说明文字
	print(" ".join(str(x) for x in B))

if __name__ == '__main__':
	main()

