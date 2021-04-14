/**
 * @author mirmu
 *
 * @param <T>
 */
public class DoubleList<T> {
	private DoubleNode<T> head;
	private DoubleNode<T> rear;
	private int numDataItems;

	public DoubleList() {
		this.head = null;
		this.rear = null;
		numDataItems = 0;
	}

	/**
	 * @param index
	 * @param newData the data that will be added to the node
	 * @throws InvalidPositionException if index is greater than numDataItems or negative it will give this error
	 */
	public void addData(int index, T newData) throws InvalidPositionException {
		if (index > numDataItems || index < 0) {
			throw new InvalidPositionException("Invalid Position");
		}
		DoubleNode<T> Node = new DoubleNode<T>(newData);
		if (rear == null & rear == null) {
			rear = Node;
			head = Node;
			numDataItems++;
			return;
		}
		if (index == 0) {
			Node.setNext(this.head);
			this.head.setPrev(Node);
			this.head = Node;
			numDataItems++;
			return;
		} else if (index == numDataItems) {
			Node.setPrev(this.rear);
			this.rear.setNext(Node);
			this.rear = Node;
			numDataItems++;
			return;
		} else {
			DoubleNode<T> tempNode = getNode(index);
			Node.setNext(tempNode);
			Node.setPrev(tempNode.getPrev());
			tempNode.getPrev().setNext(Node);
			tempNode.setPrev(Node);
			numDataItems++;
			return;
		}
	}
	
	/**
	 * @param index
	 * @return will give the node that is wanted (if index is 1 you will get the second node)
	 * @throws InvalidPositionException if index is greater than numDataItems or negative it will give this error
	 */
	public DoubleNode<T> getNode(int index) throws InvalidPositionException {
		if (index >= numDataItems || index < 0) {
			throw new InvalidPositionException("Invalid Position!");
		}
		DoubleNode<T> tempNode = this.head;
		int j = 0;
		while (tempNode != null) {
			if (j == index) {
				return tempNode;
			}
			tempNode = tempNode.getNext();
			j++;
		}
		return tempNode;
	}

	/**
	 * @param index will remove the node at which the index lies
	 * @throws InvalidPositionException if index is greater than numDataItems or negative it will give this error
	 */
	public void removeData(int index) throws InvalidPositionException {
		if (index >= numDataItems || index < 0) {
			throw new InvalidPositionException("Invalid Position!");
		}
		DoubleNode<T> tempNode; 
		if (index == 0) {
			// If only one item in list
			if (numDataItems == 1) {
				rear = null;
				head = null;
			} else {
				head = head.getNext();
				head.setPrev(null);
			}
			//This will happen regardless
			numDataItems--;
			return;
		} else if (index == numDataItems-1) {
			if (numDataItems == 1) {
				rear = null;
				head = null;
			}else {
				rear = rear.getPrev(); 
				rear.setNext(null);	
			}
			// Happens regardless 
			numDataItems--; 
			return;
		} else{	
			tempNode = getNode(index);
			tempNode.getNext().setPrev(tempNode.getPrev());
			tempNode.getPrev().setNext(tempNode.getNext());
			numDataItems--; 
			return;
		}
	}

	/**
	 * @param index
	 * @return will get the data of the node (index+1) inputed 
	 * @throws InvalidPositionException if index is greater than numDataItems or negative it will give this error
	 */
	public T getData(int index) throws InvalidPositionException {
		if (index < 0 || index >= numDataItems) {	
			throw new InvalidPositionException("Invalid Position");
		}	
		return getNode(index).getData(); 
	}
	

	/**
	 * @param index
	 * @param newData the data that you want to set in the node in (index+1)
	 * @throws InvalidPositionException if index is greater than numDataItems or negative it will give this error
	 */
	public void setData(int index, T newData) throws InvalidPositionException {
		if (index < 0 || index >= numDataItems) {
			throw new InvalidPositionException("Invalid Position!");
		}
		getNode(index).setData(newData);	
	}	
}


