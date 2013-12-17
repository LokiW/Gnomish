package gnomish;

public class SimpleModel implements Model {
	private Entity[][] places;
	public SimpleModel(int horizontal, int vertical) {
		places = new Entity[horizontal][vertical];
	}
	
	public Entity getOccupants(int x, int y) {
		if(validArgs(x,y))
			return places[x][y];
		return null;
	}
	
	public void addEntity(Entity e, int x, int y) {
		if(isFree(x,y))
				places[x][y] = e;
	}
	
	public boolean isFree(int x, int y) {
		if (validArgs(x,y) && getOccupants(x,y) == null)
			return true;
		return false;
	}
	
	private boolean validArgs(int x, int y) {
		if (x < 0 || x > places.length)
			return false;
		if (y < 0 || y > places[0].length)
			return false;
		return true;
	}
}
