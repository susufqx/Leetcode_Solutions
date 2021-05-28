package main

import "fmt"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	count := 1
	n := head.Next
	for n != nil {
		count++
		n = n.Next
	}

	k = k % count

	i := 0
	for i < k {
		node := head.Next
		if node.Next == nil {
			node.Next = head
			head.Next = nil
			head = node
		} else {
			for node.Next.Next != nil {
				node = node.Next
			}

			first := node.Next
			node.Next = nil
			first.Next = head
			head = first
		}
		i++
	}

	return head
}

func outValues(head *ListNode) {
	fmt.Println(head.Val)
	n := head.Next
	for n != nil {
		fmt.Println(n.Val)
		n = n.Next
	}
}

func main() {
	// n5 := &ListNode{5, nil}
	// n4 := &ListNode{4, n5}
	// n3 := &ListNode{3, n4}
	// n2 := &ListNode{2, n3}
	n2 := &ListNode{2, nil}
	head := &ListNode{1, n2}
	outValues(head)
	nHead := rotateRight(head, 4)
	fmt.Println("-----------")
	outValues(nHead)
}
