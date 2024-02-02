package main

// how can we approach this question?
// testcase1
// [["a","b"],["b","c"], ["a", "d"]]
// a/b=2, a/d=10, d/a=1/10, d/b=2/10, b/c=3 a/c=6 c/a=1/6
// what can we know?

// 1.if we have any common value in the equation, ex [a,b][b,d]
// we can know the relations of the rest of the value

// 2. if we have a equation, we can know the equation in changed order ex [a,b] [b,a]

// 3. if we have a variable that was defined, and we have the same values ex [a, a]
// the result is 1
// but if it is not defined, the result is -1

// Q: how will we save such data?

// node? we can save the value result as weight?
// but how would we define the direction? a/b or b/a?
// the problem here is that we cannot point to the node if the queries is given.

// map? map[rune][map[rune][float64]]
// is this great memorywise? No
//
//	struct node {
//	    from rune
//	    to rune
//	    weight float64
//	}
//
// but even if it was a node, it would always save 2 runes and a float64.
// so isnt it the same?
// lets just go with the map approach.
func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	// logic
	// create a map[rune][map[rune][float64]]
	nmap := make(map[rune]map[rune]float64)
	// for loop equations
	for i, equation := range equations {
		// save equations into the map, and unordered one
		a := []rune(equation[0])[0]
		b := []rune(equation[0])[0]
		if nmap[a] == nil {
			nmap[a] = make(map[rune]float64)
		}
		if nmap[b] == nil {
			nmap[b] = make(map[rune]float64)
		}
		nmap[a][b] = values[i]
		nmap[b][a] = 1 / values[i]
	}

	// for loop queries
	answer := make([]float64, len(queries))
	for _, query := range queries {
		visited := make(map[rune]bool)
		res := 0.0
		found := false
		dfs(&nmap, &visited, []rune{[]rune(query[0])[0], []rune(query[1])[0]}, &res, &found)
		answer = append(answer, res)
	}

	return answer
}

func dfs(nmap *map[rune]map[rune]float64, visited *map[rune]bool, input []rune, res *float64, found *bool) {
	// result already found
	if *found {
		return
	}

	// already visited
	if (*visited)[input[0]] == true {
		return
	}
	(*visited)[input[0]] = true

	// case [a,a]
	// check if the key exists on map, if so return 1, if not return -1
	if (*nmap)[input[0]] == nil {
		return
	} else if input[0] == input[1] {
		*res = 1
		*found = true
		return
		// Accessing a key that is not assigned
	} else if _, exists := (*nmap)[input[0]][input[0]]; exists {
		// case both a, b exists
		*res = (*nmap)[input[0]][input[0]]
		*found = true
		return
	} else {
		// case a exists, but b does not
		for b, _ := range (*nmap)[input[0]] {
			// c/a=2, a/c=1/2, c/d, a/d=?
			// problem save[a,c],[c,a],[c,e],[e,c],[b,d],[d,b],[e,c],[c,e] input[c,d]
			// dfs
			// [c,d] -> [a,d] -> [c,d] is visited return failed
			//       -> [e,d] -> [c,d] return result
			dfs(nmap, visited, []rune{b, input[1]}, res, found)
		}
	}
}
