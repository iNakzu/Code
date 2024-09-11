/*
    Objetivo: Metodos para arboles binarios de bsuqueda
    - Insert
    - Search
    - InOrder
    - PreOrder
    - PostOrder
*/

public class Class_05_24_2024
{
    public static void main(String[] args)
    {
        BinarySearchTree bst = new BinarySearchTree();

        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);

        bst.preOrder(bst.root);
    }

    public static class BinarySearchTree
    {
        static class Node
        {
            int value;
            Node left;
            Node right;
    
            Node(int value) {
                this.value = value;
                this.left = null;
                this.right = null;
            }
        }

        private Node root;

        public BinarySearchTree()
        {
            root = null;
        }

        public void insert(int element)
        {
            Node temp = new Node(element);

            if (root == null)
            {
                root = temp; // Si el árbol está vacío, la nueva raíz es temp
                return;     // Salimos del método
            }

            Node aux = root;
            while (aux != null)
            {
                if (aux.value > element)
                {
                    if (aux.left == null)
                    {
                        aux.left = temp;
                        return;
                    }
                    else
                    {
                        aux = aux.left;
                    }
                } else // aux.value <= element
                {
                    if (aux.right == null)
                    {
                        aux.right = temp;
                        return;
                    }
                    else
                    {
                        aux = aux.right;
                    }
                }
            }
        }

        public boolean search(Node root, int target)
        {
            if (root == null)
            {
                return false;
            }
            if (root.value == target)
            {
                return true;
            }
            if (root.value > target)
            {
                return search(root.left, target);
            }
            else 
            {
                return search(root.right, target);
            }
        }

        public void preOrder(Node root) // O(n)
        {
            if (root == null)
            {
                return;
            }
            System.out.println(root.value);
            preOrder(root.left);
            preOrder(root.right);
        }

        public void inOrder(Node root) // O(n)
        {
            if (root == null)
            {
                return;
            }
            inOrder(root.left);
            System.out.println(root.value);
            inOrder(root.right);
        }

        public void postOrder(Node root) // O(n)
        {
            if (root == null)
            {
                return;
            }
            postOrder(root.left);
            postOrder(root.right);
            System.out.println(root.value);
        }
    }
}