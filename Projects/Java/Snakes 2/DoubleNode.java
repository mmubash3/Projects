
/**
 * @author mirmu
 *
 * @param <T>
 */
public class DoubleNode<T> {
	
	private DoubleNode<T> next;
	private DoubleNode<T> prev;
	private T data;
	
	
	public DoubleNode () {
		this.data = null;
		this.next= null;
		this.prev = null;
	
	}
	
	public DoubleNode (T newData) {
		this.data = newData;
		this.next = null;
		this.prev = null;
		
	}
	
	public DoubleNode<T> getNext() {
		return next;
	}
	
	public DoubleNode<T> getPrev(){
		return prev;
	}
	
	public T getData() {
		return data;
	}
	
	public void setNext(DoubleNode<T> nextNode) {
		this.next = nextNode;
	}
	
	public void setPrev(DoubleNode<T> prevNode) {
		this.prev = prevNode;
	}
	
	public void setData (T newData) {
		this.data = newData;
	}
	
}
