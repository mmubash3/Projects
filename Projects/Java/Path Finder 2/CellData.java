
/**
 * @author mirmu
 *
 * @param <T>
 */
public class CellData<T> {

	private T id; // A reference to the identifier stored in this object
	private int value; // This is the value of the data item stored in this object

	// Constructor for the class. Initializes id to theId and value to theValue.
	public CellData(T theId, int theValue) {
		id = theId;
		value = theValue;
	}

	// Getter Methods
	//Returns instance variable value.
	public int getValue() {
		return value;
	}
	//Returns instance variable id.
	public T getId() {
		return id;
	}

	// Setter Methods
	//Assigns newValue to instance variable value.
	public void setValue(int newValue) {
		value = newValue;
	}
	//Assigns the value of newId to instance variable id
	public void setId(T newId) {
		id = newId;
	}

}
