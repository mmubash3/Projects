
public class ArrayStack<T> implements ArrayStackADT<T> {

	private T[] stack;
	private int top = -1;
	private int initialCapacity;
	private int sizeIncrease;
	private int sizeDecrease;
	private int capacity;
	
	@SuppressWarnings("unchecked")
	public ArrayStack(int initialCap, int sizeInc, int sizeDec) {
		capacity = initialCapacity;
		top = -1;
		stack = (T[])new Object[initialCapacity]; 
		sizeDecrease = sizeDec;
		sizeIncrease = sizeInc;
	}
	public void push (T dataItem) {
		if (top + 1 == stack.length) {
		      expandCapacity();   
		}
			top++; 
		    stack[top] = dataItem;
	}
	public T pop() throws EmptyStackException {
		if (top < 0) {
    		throw new EmptyStackException("The stack is empty");
    	}
		T topItem;
		if ((top < (this.length())/4) && (this.length() > initialCapacity)) {
			T[] stackDecrease = (T[])new Object[this.length()-sizeDecrease];
			for (int i = 0; i < this.size(); i++) {
				stackDecrease[i] = stack[i];
			}
			stack = stackDecrease;
			topItem = stack[top];
			stack[top] = null;
			top--;
		} else {
			topItem = stack[top];
			stack[top] = null;
			top--;
		}
		return topItem;
	}
	
	public T peek() throws EmptyStackException {
		if (isEmpty())
		      throw new EmptyStackException("Stack is Empty");
		
		    return stack[top];
	}

	public boolean isEmpty() {
		if (top == -1) {
			return true;
		} else {
			return false;
		}
	}
	
	public int size() {
		return top + 1;	
	}
	public int length() {
    	return capacity;
		
	}
	public String toString() {
		String tempString = "";
		for (int d = 0; d < top + 1; d ++) {
			if (d != top) {
				tempString += stack[d] + ", ";
			}
			else if (d == top) {
				tempString += stack[d];
				break;
			}
		}

		return "Stack: "+ tempString;
	}
	
	private void expandCapacity(){
		@SuppressWarnings("unchecked")
		T[] larger = (T[])(new Object[stack.length + sizeIncrease]);
	    
	    for (int index=0; index < stack.length; index++) {
	      larger[index] = stack[index];
	    }
	    
	    stack = larger;
	}
}
