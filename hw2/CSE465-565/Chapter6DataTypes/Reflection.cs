using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;

namespace Reflection {
	public class Point {
		public int x, y;
		public Point() {
			x = y = 0;
		}
		public Point(int X, int Y) {
			x = X;
			y = Y;
		}
		public override string ToString() {
			return String.Format("({0},{1})", x, y);
		}
	}
	public class Student {
		public String name;
		public double gpa;
		public Student() {
			name = "John Doe";
			gpa = 4.0;
		}
		public Student(String n, double GPA) {
			name = n;
			gpa = GPA;
		}
		public override string ToString()
		{ return String.Format("{0} {1}", name, gpa); }
	}

	class Program {
		public static void Examine(Object o) {
			Console.WriteLine("*********************");
			Console.WriteLine("Examining:" + o);
			Type type = o.GetType();
			Console.WriteLine("Data members");
			foreach (FieldInfo info in type.GetFields()) {
				if (info.MemberType == MemberTypes.Field) {
					Console.WriteLine(info.Name + "=" + info.GetValue(o));
				}
			}
			Console.WriteLine("Method names");
			foreach (MethodInfo method in type.GetMethods()) {
				Console.WriteLine(method.Name);
			}
		}
		public static void Set<T>(T o, String fieldName, Object v) {
			Console.WriteLine("*********************");
			Console.WriteLine("Setting:" + o + " " + fieldName + " with " + v);
			Type t = o.GetType();
			FieldInfo info = t.GetField(fieldName);
			info.SetValue(o, v);
		}
		static void Main(string[] args) {
			Point p1 = new Point(2, 3);
			Point origin = new Point(0, 0);
			Student s1 = new Student("Fred", 2.97);

			Examine(p1);
			Examine(origin);
			Examine(s1);
			Examine("some string");

			Set(origin, "y", 1000);
			Examine(origin);

			MySerializer.Tester();
		}
	}
	class MySerializer {
		public static String Serialize(Object obj)
		{ return "create some string"; }
		public static T Deserialize<T>(String str) {
			Type type = typeof(T);
			ConstructorInfo ctor = type.GetConstructor(new Type[] { });
			T obj = (T)ctor.Invoke(new Object[] { });
			return obj;
		}
		public static void Tester() {
			Point p1 = new Point(2, 3);
			Student s1 = new Student("Fred", 2.97);

			String str1 = MySerializer.Serialize(p1);
			String str2 = MySerializer.Serialize(s1);

			Console.WriteLine(str1);
			Console.WriteLine(str2);

			Point newPt = MySerializer.Deserialize<Point>(str1);
			Student newSt = MySerializer.Deserialize<Student>(str2);

			Console.WriteLine(newPt);
			Console.WriteLine(newSt);
		}
	}
}
