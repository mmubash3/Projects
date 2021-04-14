/**
 * 
 * @author mirmu
 *
 */
public class Path {
	private Map cityMap;
	
	public Path (Map theMap) {
		cityMap = theMap;
	}
	/**
	 * 
	 * @throws EmptyStackException to avoid a possible error
	 */
	public void findPath() throws EmptyStackException {
		Path path = new Path(cityMap);
		ArrayStack stack = new ArrayStack(20,2,2);
		MapCell cell = path.cityMap.getStart();
		stack.push(cell);
		
		while(!stack.isEmpty() && !cell.isDestination()) {

				MapCell currentCell =(MapCell) stack.peek();
				if (currentCell.isDestination()) {
					break;
			}
				if (path.nextCell(currentCell) != null) {
					stack.push(path.nextCell(currentCell));
					path.nextCell(currentCell).markInStack();
				}
				else{
					stack.pop();
					currentCell.markOutStack();
				}
				cell = currentCell;
				
		}
		System.out.println("Destination has been reached");
		System.out.println("Number of cells in the path:" + stack.size());
	}
	
	private MapCell nextCell(MapCell cell){
    	if (cell.isEastRoad() || cell.isWestRoad() || cell.isNorthRoad() || cell.isSouthRoad()) {
    		int i = 0;
			if (cell.isEastRoad()) {
				i = 1;
			}
    		else if (cell.isWestRoad()) {
				i = 3;
			}
			else if (cell.isNorthRoad()) {
				i = 0;
			}
			else {
				i = 2;
			}
			if (cell.getNeighbour(i) != null) {
				if (cell.getNeighbour(i).isMarked()) {
				}
				else if (cell.getNeighbour(i).isDestination()) {
		            return cell.getNeighbour(i);
		            }
				else if (cell.getNeighbour(i).isIntersection() ) {
					return cell.getNeighbour(i);
				}
		        else if ((cell.getNeighbour(i).isEastRoad() && i == 1)|| (cell.getNeighbour(i).isWestRoad() && i == 3)  || (cell.getNeighbour(i).isNorthRoad() && i == 0) || (cell.getNeighbour(i).isSouthRoad() && i == 2) ) {
		            	return cell.getNeighbour(i);
		        }
			}
            
    	}
    	else {
	        MapCell[] list = new MapCell[4];
	        for (int i = 0; i < 4; i++){
	        		
	        		if (cell.getNeighbour(i) == null)  {
	                    continue;
	                }
	        		if (cell.getNeighbour(i).isMarked()) {
	        			continue;
	        		}
	        		else if (cell.getNeighbour(i).isBlock()) {
	        			continue;
	        		}
	        		else if (cell.getNeighbour(i).isStart()) {
	        			break;
	        		}
	        		else {
	        			list[i] = cell.getNeighbour(i);
	        		}
	        }
	    
	        for (int i = 0; i< 4; i++){
	            if (list[i]== null) {
	                continue;
	            }
	            else {
	                if ((list[i].isDestination())) {
	                return cell.getNeighbour(i);
	            }
	        }
	        }
	        for (int i = 0; i< 4; i++){
	            if (list[i] == null) {
	                continue;
	            }
	            else {
	                if (list[i].isIntersection()){
	                    return cell.getNeighbour(i);
	                }
	            }
	        }
	        for (int i = 0; i< 4; i++){
	        	if (list[i] == null) {
	        		continue;
	        	}
	        	else {
	        		if (i==0 && list[i].isNorthRoad()) {
	            		return cell.getNeighbour(i);
	            	}
	            	else if (i == 1 && list[i].isEastRoad()) {
	            		return cell.getNeighbour(i);
	            	}
	            	else if (i == 2 && list[i].isSouthRoad()) {
	            		return cell.getNeighbour(i);
	            	}
	            	else if (i==3 && list[i].isWestRoad()) {
	            		return cell.getNeighbour(i);
	            	}
	        	}
	        }
    	}
		return null;
    }
	
	
}
