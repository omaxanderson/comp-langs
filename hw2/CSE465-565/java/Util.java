// Util.java

public class Util {
	public static int max(int a, int b)
	{ return a > b ? a : b; }
	public static int min(int a, int b)
	{ return a < b ? a : b; }
	private static Point mins(Point p1, Point p2) {
		int x = min(p1.getX(), p2.getX());
		int y = min(p1.getY(), p2.getY());
		return new Point(x, y);
	}
	private static Point maxs(Point p1, Point p2) {
		int x = max(p1.getX(), p2.getX());
		int y = max(p1.getY(), p2.getY());
		return new Point(x, y);
	}
	public static Point [] boundingBox(Point pts []) {
		Point [] res = new Point [2];
		res[0] = pts[0];
		res[1] = pts[0];
		for (int i=1; i<pts.length; i++) {
			res[0] = mins(res[0], pts[i]);
			res[1] = maxs(res[1], pts[i]);
		}
		return res;
	}
}
