using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Parameters {
	class Program {
		public static double f1(int b, params int [] args) {
			double sum = 0;
			foreach (int v in args) {
				sum += Math.Pow(b, v);
			}
			return sum;
		}
		public static void f2(int b, params Object [] args) {
			foreach (Object v in args) {
				Console.WriteLine(v.GetType());
			}
		}
		public static int Main(String [] args) {
			Console.WriteLine(f1(2, 3, 4, 5, 6));
			f2(2, 3, "Hello", 5, 6.5);
			return 0;
		}
	}
}
