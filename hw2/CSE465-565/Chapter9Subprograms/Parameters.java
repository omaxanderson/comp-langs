
public class Parameters {
	public static void f1(String a)
	{ a += "!"; }
	public static void f2(int a, int b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	public static void main(String [] args) {
		String s1 = "hello";

		f1(s1);

		System.out.println(s1);
		int x = 1, y = 2;
		f2(x, y);
		System.out.println(x + " " + y);
	}
}
