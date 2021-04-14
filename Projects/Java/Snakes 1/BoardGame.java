public class BoardGame {
	
	private int board_length;
	private int board_width;
	private Snake theSnake;
	private String[][] matrix;
	
	/**
	 * BoardGame constructor that opens the files and ignores two values and sets the length and width using the values obtained
	 * @param boardFile this is the file that will be opened
	 */
	public BoardGame(String boardFile){
		MyFileReader thisFile = new MyFileReader(boardFile);
		int value = thisFile.readInt();
		value = thisFile.readInt();
		board_length = thisFile.readInt();
		board_width = thisFile.readInt();
		theSnake = new Snake(thisFile.readInt(),thisFile.readInt());
		
		matrix = new String[board_width][board_length];
		int i,j ;
		for (i=0; i<board_width; i++)
			for(j=0; j<board_length; j++)
				matrix[i][j]= "empty";
		
		while (thisFile.endOfFile() == false) {
			i = thisFile.readInt();
			j = thisFile.readInt();
			matrix[i][j] = thisFile.readString();
		}
	}
		
		/**
		 * gets the matrix of the number of columns and rows entered
		 * @param row number of rows in the matrix
		 * @param col number of columns in the matrix
		 * @return
		 */
		public String getObject(int row, int col) {
			return matrix [row][col];	
		}
		
		/**
		 * this allows you to place objects on the board 
		 * @param row the row where the object is to be set
		 * @param col the column where the object is to be set
		 * @param newObject the object that will be set 
		 */
		public void setObject(int row, int col, String newObject) {
			matrix[row][col] = newObject;
		}
		
		/**
		 * is a function that returns theSnake
		 */
		public Snake getSnake() {	
			return theSnake;
		}
		
		/**
		 * allows you to set a newSnake
		 * @param newSnake
		 */
		public void setSnake(Snake newSnake) {
			theSnake = newSnake;
		}
		
		/**
		 * function to get you length of the board
		 * @return length of board
		 */
		public int getLength() {
			return board_length;
		}
		
		/**
		 * function to get you width of the board
		 * @return width of board
		 */
		public int getWidth() {
			return board_width;
		}
		
		/**
		 * 
		 * @param row
		 * @param col
		 * @return
		 */
		public String getType(int row, int col) {
			return matrix[row][col];
		}
		
	}
	