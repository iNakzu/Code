public class LinkedList
{
    private Node head;
    private static class Node
    {
        private int value;
        private Node next;

        Node(int value)
        {
            this.value = value;
        }
    }

    // Agrega un elemento al final de la lista
    public void addLast(int value)
    {
        var new_node = new Node(value);

        if (head == null)
        {
            head = new_node;
        } else
        {
            Node current = head;
            while (current.next != null)
            {
                current = current.next;
            }
            current.next = new_node;
        }
    }

    // Agrega un elemento al principio de la lista
    public void addFirst(int value)
    {
        Node new_node = new Node(value);
        new_node.next = head;
        head = new_node;
    }

    // Elimina el primer elemento con el valor dado
    public void remove(int value)
    {
        if (head == null) return;

        if (head.value == value)
        {
            head = head.next;
            return;
        }

        Node current = head;
        while (current.next != null)
        {
            if (current.next.value == value)
            {
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }

    // Busca un elemento en la lista
    public boolean contains(int value)
    {
        Node current = head;
        while (current != null)
        {
            if (current.value == value) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    // Muestra la lista
    public void print()
    {
        Node current = head;
        while (current != null)
        {
            System.out.println(current.value);
            current = current.next;
        }
    }

    public static void main(String[] args)
    {
        LinkedList list = new LinkedList();

        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        list.addLast(4);
        list.addLast(5);
        list.addLast(6);

        list.remove(2);

        System.out.println(list.contains(2));

        list.print();
    }
}

