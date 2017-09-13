using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSEnumerable {

	public class CatalogEnumerator : IEnumerator {
		public Catalog catalog;
		public bool inUGcourses;
		public int currItem;
		public CatalogEnumerator(Catalog cat) {
			this.catalog = cat;
			Reset();
		}
		public void Reset() {
			inUGcourses = true;
			currItem = -1;
		}
		public bool MoveNext() {
			currItem++;
			List<string> currList = catalog.ugClasses;

			if (inUGcourses) {
				if (currItem >= catalog.ugClasses.Count) {
					inUGcourses = false;
					currList = catalog.gradClasses;
					currItem = 0;
				}
			} else {
				currList = catalog.gradClasses;
			}
			return currItem < currList.Count;
		}
		object IEnumerator.Current {
			get
			{ return Current; }
		}
		public string Current {
			get {
				try {
					if (inUGcourses)
						return catalog.ugClasses[currItem];
					else
						return catalog.gradClasses[currItem];
				}
				catch (IndexOutOfRangeException) {
					throw new InvalidOperationException();
				}
			}
		}
	}

	public class Catalog : IEnumerable {
		public List<string> ugClasses = new List<string>();
		public List<string> gradClasses = new List<string>();
		public Catalog() {
			ugClasses.Add("CSE 174");
			ugClasses.Add("CSE 271");
			ugClasses.Add("CSE 274");
			ugClasses.Add("CSE 465");
			ugClasses.Add("CSE 486");

			gradClasses.Add("CSE 627");
			gradClasses.Add("CSE 612");
			gradClasses.Add("CSE 615");
		}
		IEnumerator IEnumerable.GetEnumerator() {
			return GetEnumerator();
		}
		public CatalogEnumerator GetEnumerator() {
			return new CatalogEnumerator(this);
		}
	}
	public class enumerable {
		public static IEnumerable<int> MyRange(int lo, int hi, int step) {
			for (int i = lo; i < hi; i+=step)
				yield return i;
		}
		static void Main(string[] args) {
			// MYRANGE
			foreach (int j in MyRange(0, 50, 3)) {
				Console.Write(j + " ");
			}
			Console.WriteLine();

			foreach (var j in Enumerable.Range(0, 50).Where(x => x % 3 == 0)) {
				Console.Write(j + " ");
			}
			Console.WriteLine();

	
			// CATALOG
			Catalog a1 = new Catalog();

			foreach (string x in a1) {
				Console.Write(x + " ");
			}
			Console.WriteLine();

			IEnumerator e1 = a1.GetEnumerator();
			while (e1.MoveNext()) {
				Console.Write(e1.Current + " ");
			}
			Console.WriteLine();
		}
	}
}
