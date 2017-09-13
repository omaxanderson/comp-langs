import java.math.*;

public class overflow {
	public static void Display(double v) {
		if (Double.isInfinite(v)) {
			System.out.println("INFINITY");
		} else if (Double.isNaN(v)) {
			System.out.println("NAN");
		} else {
			System.out.println(v);
		}
	}
	public static void main(String [] args) {
		int x = 1;
		int cnt = 0;
		Display(1.4/0.0);
		Display(0.0/0.0);
		Display(Math.sqrt(-1.0));
		Display(Double.NEGATIVE_INFINITY / Double.NEGATIVE_INFINITY);
		Display(Double.POSITIVE_INFINITY / Double.NEGATIVE_INFINITY);
		Display(Double.NEGATIVE_INFINITY / Double.POSITIVE_INFINITY);
		Display(Double.POSITIVE_INFINITY / Double.POSITIVE_INFINITY);

		while (x > 0) {
			cnt++;
			x *= 2;
		}

		System.out.println(cnt + " " + x);
	}
}
