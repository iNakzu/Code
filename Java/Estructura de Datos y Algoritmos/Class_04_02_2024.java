import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

public class Class_04_02_2024
{
    public static void main(String[] args)
    {
        Stack<Integer> stack = new Stack<Integer>(); // Create a stack

        // Add elements to the stack
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Display the stack
        System.out.println("Stack: " + stack);

        // Remove the top element from the stack
        int removedElementStack = stack.pop();
        System.out.println("Removed element: " + removedElementStack);

        // See the top element of the stack without removing it
        int topElementWithoutRemoving = stack.peek();
        System.out.println("Top element without removing: " + topElementWithoutRemoving);

        // Print the stack after removing an element
        System.out.println("Stack after removing an element: " + stack);

        // Create a queue
        Queue<Integer> queue = new LinkedList<>();

        // Add elements to the queue
        queue.add(1);
        queue.add(2);
        queue.add(3);

        // Print the queue
        System.out.println("Queue: " + queue);

        // Remove the element from the front of the queue
        int removedElementQueue = queue.poll();
        System.out.println("Removed element: " + removedElementQueue);

        // See the element at the front of the queue without removing it
        int frontElementWithoutRemoving = queue.peek();
        System.out.println("Element at the front without removing: " + frontElementWithoutRemoving);

        // Print the queue after removing an element
        System.out.println("Queue after removing an element: " + queue);

        // Create a linked list
        LinkedList<Integer> linkedList = new LinkedList<>();

        // Add elements to the linked list
        linkedList.add(1);
        linkedList.add(2);
        linkedList.add(3);

        // Print the linked list
        System.out.println("Linked list: " + linkedList);

        // Remove an element from the linked list
        linkedList.remove(1);
        System.out.println("Linked list after removing an element: " + linkedList);

        // Check if the linked list contains an element
        boolean containsElement = linkedList.contains(2);
        System.out.println("The linked list contains the element 2: " + containsElement);

        // Get the size of the linked list
        int sizeLinkedList = linkedList.size();
        System.out.println("Size of the linked list: " + sizeLinkedList);

        // Get the element at a specific position
        int elementAtIndex = linkedList.get(0);
        System.out.println("Element at index 0: " + elementAtIndex);

        // Replace an element at a specific position
        linkedList.set(0, 4);
    }
}
