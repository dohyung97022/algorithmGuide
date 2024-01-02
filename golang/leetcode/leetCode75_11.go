func isSubsequence(s string, t string) bool {
	if s == "" {
		return true
	}
	var leftS int = 0
	var rightS int = len(s) - 1
	var leftT int = 0
	var rightT int = len(t) - 1
	// if s pointers and t pointers match, increment leftS, rightS,
	// always increment left and right pointers of t
	// exception case when left and right is at the same index
	for leftT <= rightT && !(leftT == rightT && leftS != rightS) {
		if t[leftT] == s[leftS] {
			leftS++
		}
		if t[rightT] == s[rightS] {
			rightS--
		}
		if leftS > rightS {
			return true
		}
		leftT++
		rightT--
	}
	return false
}
