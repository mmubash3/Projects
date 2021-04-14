/**
 * @author mirmu
 *
 */
public class ShortestPath {
   
    CityMap cityMap;
   
    /**
     * @param cell
     * @return true or false depending on if there is a cell on any side of the road
     */
    private boolean isOneWayRoad(MapCell cell) {
        if(cell.isEastRoad() || cell.isNorthRoad() || cell.isWestRoad() || cell.isSouthRoad()) {
            return true;
        } else return false;
    }
   
    /**
     * @param theMap
     */
    public ShortestPath(CityMap theMap) {
        cityMap = theMap;
    }
   
    /**
     * will look for a path with the minimum number of map cells from the starting cell to the destination cell
     */
    public void findShortestPath() {
        OrderedCircularArray<MapCell> list = new OrderedCircularArray<MapCell>();
        MapCell beginning = cityMap.getStart();
        list.insert(beginning,0);
        beginning.markInList();
       
        boolean destinationFound = false;
       
        while(!list.isEmpty() && !destinationFound) {
            beginning = list.getSmallest();
            beginning.markOutList();
            int pathWay = 0;
           
            if (beginning.isDestination()) {
                destinationFound = true;
                System.out.println("The path found traversed " + beginning.getDistanceToStart() + " cells.");
                break;
            }
            else {
                for (int i = 0; i <= 3; i++) {
                    if (nextCell(beginning) != null) {
                        int distance = 1 + beginning.getDistanceToStart();
                        MapCell neighbor = nextCell(beginning);
                        if (neighbor.getDistanceToStart() > distance) {
                            neighbor.setDistanceToStart(distance);
                            neighbor.setPredecessor(beginning);
                        }
                        pathWay = neighbor.getDistanceToStart();
                        if ((neighbor.isMarkedInList()) && (pathWay < list.getValue(neighbor))) {
                            list.changeValue(neighbor, pathWay);
                                                                   
                        }
                        if (!neighbor.isMarkedInList()) {
                            list.insert(neighbor, pathWay);
                            neighbor.markInList();
                        }
                    }
                }
            }
        }
        if (!destinationFound) {
            System.out.println("Haha, you're stuck in middlesex! No path found >:D");
        }
    }
   
    /**
     * @param cell
     * @return  returns the first unmarked neighboring map cell that can be used to continue the path from the current one
     */
    private MapCell nextCell(MapCell cell) {
        if (isOneWayRoad(cell)) {
            int i = 0;
            if (cell.isEastRoad())
                i =1;
            else if (cell.isSouthRoad())
                i = 2;
            else if (cell.isWestRoad())
                i = 3;
 
            if (cell.getNeighbour(i) != null) {
                if (cell.getNeighbour(i).isMarked()) {}
                else if (cell.getNeighbour(i).isDestination() ||cell.getNeighbour(i).isIntersection() || isOneWayRoad(cell) )
                    return cell.getNeighbour(i);
            }
        } else {
            MapCell[] list = new MapCell[4];
            for (int i = 0;i<=3; i++){
                if (cell.getNeighbour(i) == null || cell.getNeighbour(i).isMarked() || cell.getNeighbour(i).isBlock())  {
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
                    if ((list[i].isDestination() || list[i].isIntersection() || ((i==0 && list[i].isNorthRoad())|| (i == 1 && list[i].isEastRoad()) || (i == 2 && list[i].isSouthRoad()) || (i == 3 && list[i].isWestRoad())))) {
                    return cell.getNeighbour(i);
                }
            }
           }
        }
        return null;
}
   
}