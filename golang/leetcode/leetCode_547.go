package main

func findCircleNum(isConnected [][]int) int {
	// how would we define "province"
	// how sould we find it
	// we should keep track of what city was visited
	// we should keep searching of connected cities continiously that was not visited
	// then we would say that we have found a province
	// but how would we store that information?
	// well map[int]bool could be "visited",
	// if we are done with searching as dfs,
	// we will go to the next index to search again, and when the next index city was not visited,
	// we should add another "province"

	// lets simply find if it is a province
	visited := map[int]bool{}
	cnt := 0
	for i, connection := range isConnected {
		if visited[i] == true {
			continue
		}
		visited[i] = true
		visitAllProvince(&connection, &isConnected, &visited)
		cnt++
	}
	return cnt
}

func visitAllProvince(connection *[]int, isConnected *[][]int, visited *map[int]bool) {
	for i, isCon := range *connection {
		// if no connection or alread read
		if isCon == 0 || (*visited)[i] == true {
			continue
		}
		(*visited)[i] = true
		visitAllProvince(&((*isConnected)[i]), isConnected, visited)
	}
}

// refactored, with less memory and runtime
func findCircleNumV2(isConnected [][]int) int {
	// how would we define "province"
	// how sould we find it
	// we should keep track of what city was visited
	// we should keep searching of connected cities continiously that was not visited
	// then we would say that we have found a province
	// but how would we store that information?
	// well map[int]bool could be "visited",
	// if we are done with searching as dfs,
	// we will go to the next index to search again, and when the next index city was not visited,
	// we should add another "province"

	// lets simply find if it is a province
	visited := make([]bool, len(isConnected))
	cnt := 0
	connections := [][]int{}

	for i, connection := range isConnected {
		if visited[i] == true {
			continue
		}
		visited[i] = true

		connections = append(connections, connection)
		for len(connections) != 0 {
			connection = connections[0]
			connections = connections[1:]
			for i, isCon := range connection {
				// if no connection or visited
				if isCon == 0 || visited[i] == true {
					continue
				}
				// add to visited, and add connection to read
				visited[i] = true
				connections = append(connections, isConnected[i])
			}
		}
		cnt++
	}
	return cnt
}
