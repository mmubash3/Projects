/**
 * @author mirmu
 *
 */
public class BoardGameLinked {
	private int boardLength; //the number of columns of the grid on the game board.
	private int boardWidth; //the number of rows of the grid.
	private SnakeLinked theSnake; //an object of the class SnakeLinked representing the snake.
	private DoubleList<String>[] board;


	 /**
	 * @param boardFile the file that contains all the values
	 */
	@SuppressWarnings("unchecked")
	public BoardGameLinked(String boardFile){
		MyFileReader thisFile = new MyFileReader(boardFile);
		int value = thisFile.readInt();
		value = thisFile.readInt();
		boardLength = thisFile.readInt();
		boardWidth = thisFile.readInt();
		theSnake = new SnakeLinked(thisFile.readInt(),thisFile.readInt());
		board =  new DoubleList[boardWidth];
		int i,j ;
		for (i=0; i<boardWidth; i++) {
			board[i] = new DoubleList(); 
			for (j=0; j<boardLength; j++ ) {
				board[i].addData(j, "empty");
			}
		}
		
		while (thisFile.endOfFile() == false) {
			int i1 = thisFile.readInt();
			int j1 = thisFile.readInt();
			String type = thisFile.readString();
			board[i1].getNode(j1).setData(type); 
		}
	}
	
	/**
	 * @param row
	 * @param col
	 * @return will give the object that is stored in the tile
	 * @throws InvalidPositionException if row or column is negative it will give an error, or if row or column is greater or equal to boardWidth/boardLength it will give an error
	 */
	public String getObject(int row, int col) throws InvalidPositionException{
		if (row < 0 || col < 0 || row >= boardWidth || col>= boardLength) {
			throw new InvalidPositionException("Invalid row/column entered");
		}
		return board[row].getData(col);
		
	}
	
	/**
	 * @param row
	 * @param col
	 * @param newObject the new object that will be set into the tile
	 * @throws InvalidPositionException if row or column is negative it will give an error, or if row or column is greater or equal to boardWidth/boardLength it will give an error
	 */
	public void setObject(int row, int col, String newObject) throws InvalidPositionException{
		if (row < 0 || col < 0 || row >= boardWidth || col>= boardLength) {
			throw new InvalidPositionException("Invalid row/column entered");
		}
		board[row].getNode(col).setData(newObject); 
	}
	
	//returns theSnake.
	public SnakeLinked getSnakeLinked() {
		return theSnake;
	}
	
	//stores the value of newSnake in instance variable theSnake.
	public void setSnakeLinked(SnakeLinked newSnake) {
		theSnake = newSnake;
	}
	
	//returns boardLength.
	public int getLength() {
		return boardLength;
	}
		
	//returns boardWidth.
	public int getWidth() {
		return boardWidth;
	}
}