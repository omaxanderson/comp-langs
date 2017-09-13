using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Parameters {
	class Program {
		public static void f1(String a)
		{ a += "!"; }
		public static void f2(ref String a)
		{ a += "!"; }
		public static void f3(out String a) {
			a = "";			// won't compile without initialization
			a += "!";
		}
		public static int Main(String [] args) {
			String s1 = "hello";
			String s2 = "hello";
			String s3 = "hello";
	
			f1(s1);
			f2(ref s2);
			f3(out s3);

			Console.WriteLine(s1);
			Console.WriteLine(s2);
			Console.WriteLine(s3);

			return 0;
		}
	}
}
