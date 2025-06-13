// Authored by Alex Mwangi
// BSE-05-0200/2024

package app;

// Stack implementation using an array
class DSA {
    // Constant for maximum size of the stack
    public static final int MAX = 6;

    // Array to hold stack elements
    int[] stack = new int[MAX];

    // 'top' keeps track of the topmost element in the stack
    int top = -1;

    // Method to add (push) an element onto the stack
    void push(int x) {
        // Check if the stack is already full
        if (top == MAX - 1) {
            System.out.println("The stack is full!!\n");
        } else {
            // Increment top and add the element
            stack[++top] = x;
            System.out.println(x + " has been added: \n");
        }
    }

    // Method to remove (pop) the top element from the stack
    void pop() {
        // Check if the stack is already empty
        if (top == -1) {
            System.out.println("Stack is empty!!");
        } else {
            // Remove and show the top element
            int popped = stack[top--];
            System.out.println(popped + " has been removed");
        }
    }
}

// Main class to run the program
public class APP {

    public static void main(String[] args) {
        // Create an instance of the DSA class (stack)
        DSA stacks = new DSA();

        // Push elements to the stack
        stacks.push(10);
        stacks.push(20);
        stacks.push(30);
        stacks.push(40);
        stacks.push(50);
        stacks.push(60);
        stacks.push(70);  // This one should show stack is full

        // Pop (remove) elements from the stack
        stacks.pop(); // 60 removed
        stacks.pop(); // 50 removed
        stacks.pop(); // 40 removed
        stacks.pop(); // 30 removed
        stacks.pop(); // 20 removed
        stacks.pop(); // 10 removed
        stacks.pop(); // Stack is empty
        stacks.pop(); // Stack is empty
        stacks.pop(); // Stack is empty
    }
}
