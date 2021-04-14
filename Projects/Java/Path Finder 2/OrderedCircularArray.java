
/**
 * @author mirmu
 *
 * @param <T>
 */
public class OrderedCircularArray<T> implements SortedListADT<T> {
	
	private CellData[] list; //will store the data items of the ordered list
	private int front;// stores the position of the first data item in the list
	private int rear;// is the index of the last data item in the ordered list
	private int count;// number of data items in the list.
	
	
	/**
	 * 
	 */
	@SuppressWarnings("unchecked")
	public OrderedCircularArray() {
		front = 1;
		rear = 0;
		count= 5; 
		list = (CellData<T>[]) new CellData[5];
	}
	
	/**
	 * inserts value at the position id
	 */
	public void insert (T id, int value) {
		CellData<T> data=  new CellData<T>(id, value);
		//checks if array is full
		if (!isEmpty() && size() == count) {
			CellData[] newList = new CellData[count * 2];
			int trace = front;
			int h = count+front;
			while (trace < h){
				newList[trace] = list[trace % count];
				trace = trace + 1 ;
			}
			list = newList;
			count = count * 2;
			rear = front + size() - 1;
		}
				
		if (size() == 0) {
			list[front] = data;
			rear++ ;
			rear = rear % count;
		}
		else {
			int trace = front;
			while (trace < (count * 2)) {
				if (list[trace % count] == null) {
					break;
				}
				if (value < list[trace % count].getValue()) {
					break;
				}
				trace = trace+1;
			}
			
			if ((trace % count) == rear) {
				list[(trace + 1) % count] = list[(trace) % count];
			}
			else {
				for (int i = rear; (i % count) >= trace; i --) {
					list[(i+1) % count] = list[i % count];
				}
			}
			list[trace % count] = data;
			rear++;
			rear = rear % count;	
		}
	}
	
	public int getValue(T id) throws InvalidDataItemException {
		boolean found = false;
		int position = front;
		while ((found != true) && (position != rear)) {
			if (list[position].getId().equals(id)) {
				found = true;
				break;
			}
			position = (position + 1) % list.length;
		}
		
		if (list[rear].getId().equals(id))
			found = true;
		
		if (found == false) {
			throw new InvalidDataItemException("Invalid item ID entered");
		}
		
		return list[position].getValue();
	}
	
	public void remove (T id) throws InvalidDataItemException{
		boolean found = true;
		int x = front;
		int y = 1000000000;
		count = 0;
		
		while (y > list.length) {
			if (list[x] != null) {
				if (list[x].getId().equals(id)) {
					found = false;
					break;
				}
			}
			x=x-1;
			x=x+2;
			x = x % list.length;
			y--;
		}
		if (found == true)
			throw new InvalidDataItemException("invalid id");
		
		if (count == 1) {
			list[front] = null;
			rear = 0;
			count--;
			return;
		}

		int z = list.length;
		for (int j = x - 1; j != rear; j = (j + 1) % z) {
			list[j] = list[(j + 1) % z];
		}
		list[rear] = null;

		if (rear - 1 == -1)
			rear = (rear + z - 1);
		else
			rear = rear - 1;

		if (count != 0)
			count--;

	}
		
	
	public void changeValue (T id, int newValue) throws InvalidDataItemException {
		if (isEmpty())
			throw new InvalidDataItemException("invalid id");
		this.remove(id);
		this.insert(id, newValue);
	}
	
	@SuppressWarnings("unchecked")
	public T getSmallest() throws EmptyListException {
		if (this.isEmpty())
			throw new EmptyListException("The list is empty, no smallest element");
		T smallestElement = (T) list[front];
		list[front] = null;
		front = (front + 1) % count;
		return ((CellData<T>) smallestElement).getId();
	}
	
	public boolean isEmpty() {
		for (int i = 0; i < list.length; i++) {
			if (list[i] != null) {
				return false;
			}
		}
		return true;
	}
	
	public int size() {
		int size = 0;
		for (int i = 0; i < count; i++) {
			if (list[i] != null) {
				size ++;
			}
		}
		return size;
	}
	
	public int getFront() {
		return front;
	}
	
	public int getRear() {
		return rear;
	}
	
}
