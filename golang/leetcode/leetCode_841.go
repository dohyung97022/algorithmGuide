package main

func canVisitAllRooms(rooms [][]int) bool {
	// check first room
	// recursivly visit rooms with keys
	// map?
	// no, how would we know that we visited all the rooms?
	// maybe by visits[]bool, if we visit the room for the first time, we add to the cnt
	// and if the cnt is equal to the len(rooms), then we should return true.
	// and we should only visit if the visits[]bool was false and turned into true.

	visits := map[int]bool{0: true}
	visitCnt := 1
	visit([]int{0}, &rooms, &visits, &visitCnt)
	if visitCnt == len(rooms) {
		return true
	} else {
		return false
	}
}

func visit(keys []int, rooms *[][]int, visits *map[int]bool, visitCnt *int) {
	foundKeys := []int{}
	for _, key := range keys {
		for _, roomKey := range (*rooms)[key] {
			if (*visits)[roomKey] == true {
				continue
			} else {
				(*visits)[roomKey] = true
				*visitCnt++
				foundKeys = append(foundKeys, roomKey)
			}
		}
	}
	if len(foundKeys) != 0 {
		visit(foundKeys, rooms, visits, visitCnt)
	}
}

// refactored faster version
// does not recursivly go in function
// for len(keys) != 0 {
func canVisitAllRoomsV2(rooms [][]int) bool {
	// check first room
	// recursivly visit rooms with keys
	// map?
	// no, how would we know that we visited all the rooms?
	// maybe by visits[]bool, if we visit the room for the first time, we add to the cnt
	// and if the cnt is equal to the len(rooms), then we should return true.
	// and we should only visit if the visits[]bool was false and turned into true.

	visits := map[int]bool{0: true}
	keys := []int{0}
	for len(keys) != 0 {
		foundKeys := []int{}
		for _, key := range keys {
			for _, roomKey := range rooms[key] {
				if visits[roomKey] == true {
					continue
				}
				visits[roomKey] = true
				foundKeys = append(foundKeys, roomKey)
			}
		}
		keys = foundKeys
	}

	if len(visits) == len(rooms) {
		return true
	}
	return false
}
