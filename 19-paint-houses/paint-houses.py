def min_cost(costs):
	previous_min = 0
	previous_second_min = 0
	previous_color = None
	for i in range(len(costs)):
		current_min = float("inf")
		current_second_min = float("inf")
		current_color = None

		for j in range(len(costs[i])):
			if j == previous_color:
				costs[i][j] += previous_second_min
			else:
				costs[i][j] += previous_min

			if costs[i][j] < current_min:
				current_second_min = current_min
				current_min = costs[i][j]
				current_color = j
			elif costs[i][j] < current_second_min:
				current_second_min = costs[i][j]

		previous_color = current_color
		previous_min = current_min
		previous_second_min = current_second_min

	res = float("inf")
	for i in range(len(costs[0])):
		if costs[len(costs) - 1][i] < res:
			res = costs[len(costs) - 1][i]
	return res

def main():
	costs = [[13, 2, 1],
			 [4, 2, 1],
			 [4, 6, 8],
			 [2, 11, 19]]
	print(min_cost(costs))

if __name__ == "__main__":
	main()