

public class Snake {

	private int snakeLength;
	private Position[] snakeBody;
	
	public Snake(int row, int col) {
		snakeLength = 1;
		snakeBody = new Position[5];
		Position object = new Position(row, col);
		snakeBody[0] = object;
	}
	
	public int getLength() {
		return snakeLength;
	}
	
	public Position getPosition(int index) {
		if(index < 0) {
			return null;
		} else if(index >= snakeLength) {
			return null;
		} else
			return snakeBody[index];
	}
	
	public void shrink() {
		snakeLength--;
	}
	
	public boolean snakePosition(Position pos) {
		for(int i =0; i<snakeLength; i++) {
			if(pos.equals(snakeBody[i]))
				return true;
		}
		return false;
	}
	
	public Position newHeadPosition(String direction) {
		Position temp = new Position(snakeBody[0].getRow(), snakeBody[0].getCol());
		switch(direction) {
			case "up":
				temp.setRow((temp.getRow())-1);
				return temp;
			case "down":
				temp.setRow((temp.getRow())+1);
				return temp;
			case "right":
				temp.setCol((temp.getCol())+1);
				return temp;
			case "left":
				temp.setCol((temp.getCol())-1);
				return temp;
		}
		return null;
	} 
	
	public void moveSnake(String direction) {
		Position temp;
		int i = snakeLength;
		while (i>1){
			temp = snakeBody[i-2];
			snakeBody[i -1] = temp;
			i--;
		}
		snakeBody[0] = newHeadPosition(direction);
	}
	
	public void grow(String direction) {
		//Creating a new variable, arrayLength to keep track of how big the array is, and to use it to see if we need to make the array bigger
		int arrayLength;
		//If the snakeLength <= 5 that means we are still the same size as the initial array. So we set it to 5.
		if(snakeLength <= 5) {
			arrayLength = 5;
		} else {
			//otherwise, the array size has been modified by our functions below, which work at multiples of 5.
			
			//Notice that below I am taking advantage of INTEGER division. So, 6/5 = 1 instead of 1.2, and so 6/5 * 5 = 5
			//Then, because we have that remainder, we need to double the size of the array, so we test if the modulo of snakeLength > 0, if so that means we need to double the array. 
			arrayLength = snakeLength/5;
			arrayLength = arrayLength*5;
			//what if we had snakeLength = 12? We just set the array to = 10, which is too small, so we need to double it, to make it 20, and this is where we check if the modulo of the ORIGINAL variable
			//(snakeLength) is > 0, if so that means we have a remainder and we need to double the array.
			if(snakeLength%5 > 0) {
				arrayLength = arrayLength*2;
			}
		}
		
		//newSnakeHead is a temporary variable that I use to calculate the new value of the snake head, I save it as its own variable
		//so that if we need to reset the array (to double it) we have the value saved.
		Position newSnakeHead;
		//This temporary array is what I use to shift everything to the right AND to save the data when I need to double the array size.
		Position[] tempArr = new Position[snakeLength*2];

		//Looping through the arrays and copying the values by shifting it 1 to the right.
		for(int i=0; i<snakeLength; i++) {
			tempArr[i+1] = snakeBody[i]; 
		}
		//Calculating the new snake head position
		newSnakeHead = newHeadPosition(direction);
		
		//Now, i'm incrementing the snakeLength
		snakeLength++;
		
		//If the new Snake length is greater than the current array length, then we need to double the array length
		if(snakeLength>arrayLength) {
			//Resetting the array to double the length (This also wipes all the data)
			snakeBody = new Position[(snakeLength-1)*2]; //Notice the -1, this is because we want to keep it as multiples of 5. (so when it's 6, it does 5*2).
		}
		//Setting the new head of the snake that was calculated earlier
		snakeBody[0] = newSnakeHead;
		
		//Looping through the arrays again to copy the data back.
		for(int i=1; i <(snakeLength); i++) {
			snakeBody[i] = tempArr[i];
		}
	}
	
}