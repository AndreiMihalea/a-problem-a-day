class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def serialize(node, arr):
	if not node:
		arr.append(-1)
		return
	arr.append(node.val)
	serialize(node.left, arr)
	serialize(node.right, arr)

def deserialize(arr):
	if arr[0] == -1:
		arr.pop(0)
		return None
	
	node = Node(arr[0])
	arr.pop(0)
	node.left = deserialize(arr)
	node.right = deserialize(arr)

	return node

def equal_tree(n1, n2):
	if not n1 and not n2:
		return True
	elif n1 and n2:
		return n1.val == n2.val and equal_tree(n1.left, n2.left) and equal_tree(n1.right, n2.right)
	return False

def main():
	node = Node(20)
	node.left = Node(11)
	node.right = Node(23)
	node.left.left = Node(8)
	node.left.right = Node(15)
	node.right.right = Node(28)
	node.right.right.right = Node(31)
	node.right.right.right.left = Node(29)
	node.right.right.right.right = Node(35)

	res = []
	serialize(node, res)
	print(res)

	node1 = deserialize(res)

	res = []
	serialize(node1, res)
	print(res)

	print(equal_tree(node, node1))

if __name__ == "__main__":
	main()