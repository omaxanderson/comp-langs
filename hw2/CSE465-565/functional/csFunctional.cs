using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSFunctional {
	class FunctionalExamples {
		public static void Print(IEnumerable<int> items)
		{
			foreach (int v in items) {
				Console.Write(v + " ");
			}
			Console.WriteLine();
		}
		/******************************************************************/
		public delegate int IntFunc(int x);
		public delegate String StringFunc(String s);

		public static int echo(int x)
		{
			return x;
		}
		public static int sqr(int x)
		{
			return x*x;
		}
		public static int sum(int N, IntFunc f)
		{
			int sum = 0;
			for (int i = 0; i <= N; i++) {
				sum += f(i);
			}
			return sum;
		}
		static void DelegateExample()
		{
			Console.WriteLine("Start DelegateExample");
			const int N = 5;
			Console.WriteLine(N*N);
			Console.WriteLine(sqr(N));

			Console.WriteLine(sum(100, echo));
			Console.WriteLine(sum(100, sqr));
			Console.WriteLine(sum(100, x => x * x * x));

			StringFunc F = str =>
			{
				return str + " World";
			};
			Console.WriteLine(F("Hello"));

			Func<int, int, int, bool> ordered = (x, y, z) => x <= y && y <= z;
			Console.WriteLine(ordered(4, 8, 12));
			Console.WriteLine(ordered(4, 12, 8));
			Console.WriteLine();
		}

		/******************************************************************/
		public static void ApplyToAll(int[] ary, IntFunc F)
		{
			for (int i = 0; i < ary.Length; i++) {
				ary[i] = F(ary[i]);
			}
		}
		public static int accumulate(IEnumerable<int> items, Func<int, int, int> op)
		{
			if (items.Count() == 0) {
				throw new Exception("Can't send in empty container to accumulate");
			}
			bool firstTime = true;
			int result = items.First();

			foreach (int v in items) {
				if (firstTime) {
					firstTime = false; // skip first one
				} else {
					result = op(result, v);
				}
			}
			
			return result;
		}
		static void ApplyToAllExample()
		{
			Console.WriteLine("ApplyToAllExample");
			int[] A = { 1, 2, 3, 4, 5 };

			Console.WriteLine(accumulate(A, (x, y) => x + y));
			Console.WriteLine(accumulate(A, (x, y) => x * y));

			Print(A);
			ApplyToAll(A, sqr);
			Print(A);
			ApplyToAll(A, x => 2 * x);
			Print(A);
			Console.WriteLine();
		}
		/******************************************************************/
		public static Random r = new Random();
		public static bool isPositive(int x)
		{ return x > 0;  }
		public static int myrandom()
		{ return r.Next(21) - 10; }
		static void LinqExample()
		{
			Console.WriteLine("Start LinqExample");
			List<int> items = new List<int>();
			for (int i = 0; i < 10; i++) {
				items.Add(myrandom());
			}

			Print(items);
			Print(items.Where(isPositive));
			Print(items.Where(x => x > 0));
			Print(items.Where(isPositive).Select(x => x * x));
			Print(items);
		}
		/******************************************************************/
		public static void Main(String[] args)
		{
			DelegateExample();
			ApplyToAllExample();
			LinqExample();
		}
	}
}
