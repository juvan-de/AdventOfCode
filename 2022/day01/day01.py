inventories = open("input.txt").read().split("\n\n")

calories = []


for inventory in inventories:
	elve_calories = 0
	seperates = inventory.split("\n")
	for count in seperates:
		elve_calories += int(count)
	calories.append(elve_calories)
calories.sort()
calories.reverse()
print(calories[0] + calories[1] + calories[2])