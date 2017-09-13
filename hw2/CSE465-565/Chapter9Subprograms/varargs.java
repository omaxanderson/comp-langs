
public class varargs {
	public static void f1(int ... nums) {
		System.out.println("Num params : " + nums.length);
		for (int j : nums) {
			System.out.println(j);
		}
	}
	public static void main(String [] args) {
		f1(1,2,3,4,5,6);
	}
}
