package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isCompleteTree(root *TreeNode) bool {
	tempList := []*TreeNode{}
	tempList = append(tempList, root)
	index := 0
	for index < len(tempList) {
		bt := tempList[index]
		index++
		if bt == nil {
			continue
		}

		left := bt.Left
		right := bt.Right
		if left == nil && right != nil {
			return false
		}

		tempList = append(tempList, bt.Left)
		tempList = append(tempList, bt.Right)
	}

	for i := 0; i < len(tempList)-1; i++ {
		if tempList[i] == nil && tempList[i+1] != nil {
			return false
		}
	}

	return true
}
