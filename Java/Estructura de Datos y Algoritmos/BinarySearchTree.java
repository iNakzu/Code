public class BinarySearchTree
{
    private Node root;

    static class Node
    {
        int value;
        Node left;
        Node right;
    
        Node(int value)
        {
            this.value = value;
            left = right = null;
        }
    }

    BinarySearchTree()
    {
        this.root = null;
    }

    public static void main(String[] args)
    {
        BinarySearchTree bst = new BinarySearchTree();
    }
}