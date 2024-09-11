/*
    Level order traversal binary tree & print tree
*/

import java.util.Queue;
import java.util.LinkedList;

public class Class_05_28_2024 {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        // Insert nodes in the bst
        bst.insert(1);
        bst.insert(1);
        bst.insert(2);
        bst.insert(3);
        bst.insert(0);
        bst.insert(5);
        bst.insert(7);

        bst.printTree(bst.root, "", true);

        bst.search(7);

        System.out.println(bst.height(bst.root));
    }

    public static class BinarySearchTree {
        public class Node {
            int value;
            Node left;
            Node right;

            Node(int value) {
                this.value = value;
                left = right = null;
            }
        }

        private Node root;

        BinarySearchTree() {
            this.root = null;
        }

        public void insert(int value) {
            Node temp = new Node(value);

            if (root == null) {
                root = temp; // If the tree is empty, the new root is temp
                return; // Exit the method
            }

            Node aux = root;

            while (aux != null) {
                if (value < aux.value) {
                    if (aux.left == null) {
                        aux.left = temp;
                        return;
                    } else {
                        aux = aux.left;
                    }
                } else // value >= aux.value
                {
                    if (aux.right == null) {
                        aux.right = temp;
                        return;
                    } else {
                        aux = aux.right;
                    }
                }
            }
        }

        public void search(int value) {
            Node current = root;

            while (current != null) {
                if (value < current.value) {
                    current = current.left;
                } else if (value > current.value) {
                    current = current.right;
                } else {
                    System.out.println("The value " + value + " is found in the tree");
                    return;
                }
            }

            System.out.println("The value " + value + " is not found in the tree");
        }

        public int height(Node root) {
            if (root == null) {
                return -1;
            }

            int leftHeight = height(root.left);
            int rightHeight = height(root.right);

            if (leftHeight > rightHeight) {
                return leftHeight + 1;
            } else {
                return rightHeight + 1;
            }
        }

        public boolean isBalanced(Node node)
        {
            if (node == null)
            {
                return true;
            }

            int leftHeight = height(node.left);
            int rightHeight = height(node.right);

            if (Math.abs(leftHeight - rightHeight) <= 1 && isBalanced(node.left) && isBalanced(node.right))
            {
                return true;
            }

            return false;
        }

        public void levelOrder() {
            if (root == null) {
                return; // Empty tree
            }

            Queue<Node> queue = new LinkedList<>();
            queue.offer(root); // Enqueue the root

            while (!queue.isEmpty()) {
                Node currentNode = queue.poll(); // Dequeue the current node
                System.out.println(currentNode.value); // Process the node

                // Enqueue the children (if any)
                if (currentNode.left != null) {
                    queue.offer(currentNode.left);
                }
                if (currentNode.right != null) {
                    queue.offer(currentNode.right);
                }
            }
        }

        public void printTree(Node node, String prefix, boolean isTail) {
            if (node.right != null) {
                printTree(node.right, prefix + (isTail ? "│   " : "    "), false);
            }

            System.out.println(prefix + (isTail ? "└── " : "┌── ") + node.value);

            if (node.left != null) {
                printTree(node.left, prefix + (isTail ? "    " : "│   "), true);
            }
        }
    }
}
