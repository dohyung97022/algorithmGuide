package main

import "container/heap"

// TODO : retake this problem
// TODO : you have not understood it well enough.

type Data struct {
	isLeft bool
	value  int
}
type Heap []Data

func (h Heap) Len() int {
	return len(h)
}
func (h Heap) Less(i int, j int) bool {
	if h[i].value == h[j].value {
		return h[i].isLeft
	}
	return h[i].value < h[j].value
}
func (h Heap) Swap(i int, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *Heap) Pop() interface{} {
	el := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return el
}
func (h *Heap) Push(i interface{}) {
	*h = append(*h, i.(Data))
}

func totalCost(costs []int, k int, candidates int) int64 {
	minHeap := &Heap{}

	for i := 0; i < candidates; i++ {
		*minHeap = append(*minHeap, Data{isLeft: true, value: costs[i]})
	}

	for i := len(costs) - candidates; i < len(costs); i++ {
		*minHeap = append(*minHeap, Data{isLeft: false, value: costs[i]})
	}

	heap.Init(minHeap)
	res := 0

	for i := 0; i < k; i++ {
		worker := heap.Pop(minHeap).(Data)
		res += worker.value
	}
	return int64(res)
}
