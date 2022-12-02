rounds = open("input.txt").read().split("\n")

outcomes = {
	"A": 0,
	"B": 1,
	"C": 2,
}


totalScore = 0
for match in rounds:
	letters = match.split(" ")
	if (letters[1] == "X"):
		totalScore += ((outcomes[letters[0]] + 2) % 3) + 1
		# print (totalScore)
	elif (letters[1] == "Y"):
		totalScore += 3 + (outcomes[letters[0]] + 1)
		# print (totalScore)
	elif (letters[1] == "Z"):
		totalScore += 7 + ((outcomes[letters[0]] + 1) % 3)
print (totalScore)

