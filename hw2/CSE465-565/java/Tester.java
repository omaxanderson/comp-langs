// Tester.java
//
//Output:
//(500,500)
//(-2,10)
//(23,453)
//(500,500)
//Bounding box:
//(-2,10)
//(500,500)


public class Tester {
	
	public static byte b; 
	public static short s;
	public static int i;
	public static long l;
	public static boolean isTrue;
	public static float f;
	public static double d;
	public static char ch;
	
	public static void main(String[] args) {
		Point p1 = new Point(2, 3);
		Point p2 = new Point(-2, 10);
		Point p3 = Point.parsePoint("(23,453)");
		Point p4 = p1;
		p4.setX(500);
		p4.setY(500);
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
		System.out.println(p4);

		Point [] pts = {p1, p2, p3};
		Point [] bb = Util.boundingBox(pts);
		Point mn = bb[0];
		Point mx = bb[1];
		System.out.println("Bounding box:");
		System.out.println(mn);
		System.out.println(mx);
	}
}
