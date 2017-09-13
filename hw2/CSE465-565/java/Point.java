// Point.java

import java.util.*;

public class Point {
	public Point()
	{ x = y = 0; } // or: this(0, 0);
	public Point(int X, int Y) {
		x = X;
		y = Y;
	}
	public String toString()
	{ return "(" + x + "," + y + ")"; }
	public static Point parsePoint(String s) {
		StringTokenizer toks = new StringTokenizer(s, "(),");
		String string1 = toks.nextToken();
		String string2 = toks.nextToken();
		int x = Integer.parseInt(string1);
		int y = Integer.parseInt(string2);
		return new Point(x, y);
	}
	public int getX()
	{ return x; }
	public int getY()
	{ return y; }
	void setX(int X)
	{ x = X; }
	void setY(int Y)
	{ y = Y; }
	public int quadrant() {
		if (x > 0 && y > 0) {
			return 1;
		} else if (x < 0 && y > 0) {
			return 2;
		} else if (x < 0 && y < 0) {
			return 3;
		} else if (x > 0 && y < 0) {
			return 4;
		} else {
			return -1;
		}
	}
	
	private int x;
	private int y;
}
