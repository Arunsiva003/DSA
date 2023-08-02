public class stack {
    private int top;
    private int[] arr;

    public stack(int size) {
        arr = new int[size];
        top = -1;
    }

    public void push(int data) {
        if (top == arr.length - 1) {
            System.out.println("Stack overflow");
            return;
        }
        arr[++top] = data;
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Stack underflow");
            return -1;
        }
        return arr[top--];
    }

    public int peek() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return -1;
        }
        return arr[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int size() {
        return top + 1;
    }

    public static void main(String[] args) {
        stack stack = new stack(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        System.out.println("Peek: " + stack.peek()); // Peek: 5
        System.out.println("Pop: " + stack.pop()); // Pop: 5
        System.out.println("Size: " + stack.size()); // Size: 4
        System.out.println("Pop: " + stack.pop()); // Pop: 4
        System.out.println("Size: " + stack.size()); // Size: 3
        System.out.println("Peek: " + stack.peek()); // Peek: 3
        System.out.println("Pop: " + stack.pop()); // Pop: 3
        System.out.println("Size: " + stack.size()); // Size: 2
        System.out.println("Pop: " + stack.pop()); // Pop: 2
        System.out.println("Size: " + stack.size()); // Size: 1
        System.out.println("Pop: " + stack.pop()); // Pop: 1
        System.out.println("Size: " + stack.size()); // Size: 0
        System.out.println("Pop: " + stack.pop()); // Stack underflow
    }
}