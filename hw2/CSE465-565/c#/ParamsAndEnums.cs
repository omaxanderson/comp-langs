using System;

namespace cs
{
	enum Color {
		Red, Green, Blue, Yellow, Cyan=10, Magenta, White, Black
	};
	enum Orientation {
		Horizontal, Vertical
	};

	public class ParamsAndEnums
	{
		public static void f(int a, out int b, ref int c)
		{
			int x = 1;
			a = 1;		// value param
			// x = b;	// illegal, b must be set first
			b = 2;
			c = 0;
			x = c;
		}
		public static void dump()
		{
			Type type = typeof(Color);
			Array values = Enum.GetValues(type);
			foreach (object v in values) {
				Console.WriteLine(v + " " + (int)v);
			}
		}
		public static void Main()
		{
			dump();
			int a=1, y, z=3;
			f(a, out y, ref z);
		}
	}
}
