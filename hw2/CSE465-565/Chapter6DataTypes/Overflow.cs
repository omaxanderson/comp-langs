using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OverflowCS {
	public class OverflowExample {
		public static void Display(double v) {
			if (Double.IsInfinity(v)) {
				Console.WriteLine("INFINITY");
			} else if (Double.IsNaN(v)) {
				Console.WriteLine("NAN");
			} else {
				Console.WriteLine(v);
			}
		}
		public static void Main(String [] args) {
			int x = 1;
			int cnt = 0;
			Display(1.4/0.0);
			Display(0.0/0.0);
			Display(Math.Sqrt(-1.0));
			Display(Double.NegativeInfinity / Double.NegativeInfinity );
			Display(Double.PositiveInfinity  / Double.NegativeInfinity );
			Display(Double.NegativeInfinity  / Double.PositiveInfinity);
			Display(Double.PositiveInfinity / Double.PositiveInfinity);

			x = 1;
			while (x > 0) {
				cnt++;
				x *= 2;
			}
			Console.WriteLine(cnt + " " + x);

			x = 1;
			try {
				while (x > 0) {
					cnt++;
					x = checked(x * 2);
				}
				Console.WriteLine(cnt + " " + x);
			}
			catch (System.OverflowException e) {
				Console.WriteLine(e.StackTrace);
			}
		}
	}
}
