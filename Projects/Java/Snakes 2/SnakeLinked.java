/**
 * @author mirmu
 *
 */
public class SnakeLinked {
	private int snakeLength;
	private DoubleList<Position> snakeBody;
	
	/**
	 * @param row enter the row value
	 * @param col enter the column value
	 */
	public SnakeLinked(int row, int col) {
		snakeLength = 1;
		Position P= new Position(row, col);
		snakeBody = new DoubleList();
		snakeBody.addData(0, P);
	}
	

	public int getLength() {
		return snakeLength;
	}
	
	/**
	 * @param index 
	 * @return if index is greater than snakeLength or if smaller than 0 it will be null or it will give the data in that index
	 */
	public Position getPosition(int index) {
		if (index >= snakeLength || index < 0) {
			return null;
		}
		else {
			return snakeBody.getData(index);
		}
	}
	
	/**
	 * @param pos
	 * @return
	 */
	public boolean snakePosition(Position pos) {
		int size = this.getLength();
		for(int i=0; i<size; i++) {
			if(getPosition(i).equals(pos)){
				return true;
			}
		}
		return false;
	}
	
		/**
		 * @param direction 
		 * @return depending on direction the row and column values will change respectively
		 */
		public Position newHeadPosition(String direction) {
			
				Position newHead = snakeBody.getNode(0).getData(); 
				int row = newHead.getRow();
				int col = newHead.getCol(); 
				
				if(direction.equals("left")) {
					col = col -1; 	
				}
				else if(direction.equals("right")) {
					col = col + 1; 
				}
				else if(direction.equals("up")) {	
					row = row-1;
				}
				else if(direction.equals("down")) {		
					row = row+1; 
				}
			return new Position(row, col); 
			}
	
		/**
		 * @param direction
		 */
		public void moveSnakeLinked(String direction) {
		if(this.snakeLength == 1) {
			snakeBody.setData(0, newHeadPosition(direction)); 
			return;
		}
		
		int Snakei = snakeLength-1;
	
		do {
			snakeBody.setData(Snakei, snakeBody.getData(Snakei-1)); 
			 Snakei--; 
		}
		while(Snakei >= 1 ); 	
			snakeBody.setData(0, newHeadPosition(direction)); 		
		} 

		
	public void shrink() {
		this.snakeBody.removeData(this.snakeLength-1);
		this.snakeLength = this.snakeLength-1;
	}
		public void grow(String direction) {
			snakeBody.addData(0, newHeadPosition(direction));
				 this.snakeLength++; 
			}		
}
