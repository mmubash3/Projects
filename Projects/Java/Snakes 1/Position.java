
public class Position {
	
	private int positionRow;
	private int positionColumn;
	
	/**
	 * This is the constructor for class Position which initializes positionRow and positionColumn
	 * @param row
	 * @param col
	 */
	public Position(int row, int col) {
		this.positionRow = row;
		this.positionColumn= col;
		
	}	
	
	/**
	 * gets the Row position
	 * @return position of Row
	 */
	public int getRow() {
		return positionRow;
	}
	
	/**
	 * gets the Column position
	 * @return position of column
	 */
	public int getCol() {
		return positionColumn;
	}
	
	/**
	 * sets the row
	 * @param newRow new row that is to be set
	 */
	public void setRow(int newRow) {
		positionRow = newRow;
	}
	
	/**
	 * sets the column 
	 * @param newCol new column to be set
	 */
	public void setCol(int newCol) {
		positionColumn = newCol;
	}
	
	/**
	 * compares if both objects have the same co-ordinates
	 * @param otherPosition position to be compared to
	 * @return
	 */
	public boolean equals(Position otherPosition) {
		if(otherPosition.getCol() == getCol() && otherPosition.getRow() == getRow())
			return true;
		else
			return false;	
	}
	
}
