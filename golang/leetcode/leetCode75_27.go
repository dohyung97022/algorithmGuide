package main

type RecentCounter struct {
	requests []int
}

func Constructor() RecentCounter {
	return RecentCounter{requests: []int{}}
}

func (this *RecentCounter) Ping(t int) int {
	this.requests = append(this.requests, t)
	t = t - 3000
	i := 0
	for this.requests[i] < t {
		i++
	}
	this.requests = this.requests[i:]
	return len(this.requests)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
