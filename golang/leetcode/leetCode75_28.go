package main

func predictPartyVictory(senate string) string {
	var dRemoveCnt int
	var rRemoveCnt int
	return round(&senate, &dRemoveCnt, &rRemoveCnt)
}

func round(senate *string, dRemoveCnt *int, rRemoveCnt *int) string {
	dExists := false
	rExists := false
	for i := 0; i < len(*senate); i++ {
		// if index is r and rRemoveCnt > 0
		if (*senate)[i] == 'R' && *rRemoveCnt > 0 {
			// remove r
			*rRemoveCnt--
			*senate = (*senate)[:i] + (*senate)[i+1:]
			i--
		} else if (*senate)[i] == 'D' && *dRemoveCnt > 0 {
			// else if index is d and dRemoveCnt > 0
			// remove d
			*dRemoveCnt--
			*senate = (*senate)[:i] + (*senate)[i+1:]
			i--
		} else if (*senate)[i] == 'R' {
			// else if index is r
			// add dRemoveCnt rExists = true
			*dRemoveCnt++
			rExists = true
		} else if (*senate)[i] == 'D' {
			// else if index is d
			// add rRemoveCnt dExists = true
			*rRemoveCnt++
			dExists = true
		}
	}
	// if rExists && dExists
	// start a new round
	if rExists && dExists {
		return round(senate, dRemoveCnt, rRemoveCnt)
	} else if rExists {
		return "Radiant"
	} else {
		return "Dire"
	}
}
