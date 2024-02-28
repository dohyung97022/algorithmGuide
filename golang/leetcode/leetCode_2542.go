package main

import "container/heap"

type minHeap []int

func (h minHeap) Len() int               { return len(h) }
func (h minHeap) Less(i int, j int) bool { return h[i] < h[j] }
func (h minHeap) Swap(i int, j int)      { h[i], h[j] = h[j], h[i] }
func (h *minHeap) Pop() interface{} {
	el := (*h)[len(*h)-1]
	*h = (*h)[0 : len(*h)-1]
	return el
}
func (h *minHeap) Push(i interface{}) {
	*h = append(*h, i.(int))
}

type maxHeap []int

func (h maxHeap) Len() int               { return len(h) }
func (h maxHeap) Less(i int, j int) bool { return h[i] > h[j] }
func (h maxHeap) Swap(i int, j int)      { h[i], h[j] = h[j], h[i] }
func (h *maxHeap) Pop() interface{} {
	el := (*h)[len(*h)-1]
	*h = (*h)[0 : len(*h)-1]
	return el
}
func (h *maxHeap) Push(i interface{}) {
	*h = append(*h, i.(int))
}

func maxScore(nums1 []int, nums2 []int, k int) int64 {
	maxHeap := &maxHeap{}
	*maxHeap = append(*maxHeap, nums1...)
	heap.Init(maxHeap)

	minHeap := &minHeap{}
	*minHeap = append(*minHeap, nums2...)
	heap.Init(minHeap)

	nums1Sum, nums2Sum := 0, 0

	for i := 0; i < k; i++ {
		nums1Sum += heap.Pop(maxHeap).(int)
		nums2Sum += heap.Pop(minHeap).(int)
	}
	return int64(nums1Sum * nums2Sum)
}
