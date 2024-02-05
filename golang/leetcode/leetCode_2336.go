package main

import "container/heap"

type SmallestInfiniteSet struct {
	set    []int
	setMap map[int]bool
}

func Constructor() SmallestInfiniteSet {
	smallestInfinateSet := SmallestInfiniteSet{set: make([]int, 1000), setMap: make(map[int]bool)}
	for i := 0; i < len(smallestInfinateSet.set); i++ {
		smallestInfinateSet.set[i] = i + 1
		smallestInfinateSet.setMap[i] = true
	}
	return smallestInfinateSet
}

func (h SmallestInfiniteSet) Len() int           { return len(h.set) }
func (h SmallestInfiniteSet) Less(i, j int) bool { return h.set[i] < h.set[j] }
func (h SmallestInfiniteSet) Swap(i, j int)      { h.set[i], h.set[j] = h.set[j], h.set[i] }
func (h *SmallestInfiniteSet) Push(x any)        { (*h).set = append((*h).set, x.(int)) }
func (h *SmallestInfiniteSet) Pop() any {
	old := (*h).set
	n := len(old)
	x := old[n-1]
	(*h).set = old[0 : n-1]
	return x
}

func (this *SmallestInfiniteSet) PopSmallest() int {
	min := heap.Pop(this).(int)
	(*this).setMap[min] = false
	return min
}

func (this *SmallestInfiniteSet) AddBack(num int) {
	if !(*this).setMap[num] {
		(*this).setMap[num] = true
		heap.Push(this, num)
	}
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */
