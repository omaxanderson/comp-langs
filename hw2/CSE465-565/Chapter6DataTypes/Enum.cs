using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Enums {
	public enum Color { Red, Green, Blue, White, Black, Gray };
	class Program {
		static void Main(string[] args) {
			Color c1 = Color.Red;
			Color c2 = (Color)4;
            Color c3 = (Color)Enum.Parse(typeof(Color), "White");
			Console.WriteLine(c1);
			Console.WriteLine(c2);
			Console.WriteLine(c3);
            Console.WriteLine(Enum.GetName(typeof(Color), Color.Blue));
			
            String [] names = Enum.GetNames(typeof(Color));
            foreach (String n in names) {
            	Console.Write(n + " ");
			}
            Console.WriteLine();

           	Array vals = Enum.GetValues(typeof(Color));
           	foreach (Object o in vals) {
           		Console.Write(o + " ");
			}
           	Console.WriteLine();
       	}
	}
}
