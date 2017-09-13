
using System;
using System.Collections.Generic;
using System.IO;
namespace MailMerge {
public class Program {	
	
	public static void getRecords(StreamReader input, out List<string[]> records) {
		records = new List<string[]>();
		while (!input.EndOfStream) {
			string[] toks = input.ReadLine().Split('\t');
			records.Add(toks);
		}
	}

	public static void writeRecords(List<string[]> records, string templateFileName) {
		// create a dictionary with the attribute name and index
		Dictionary<string, int> attributes = new Dictionary<string, int>();
		for (int i = 0; i < records[0].Length; i++) {
			attributes[records[0][i]] = i;
		}
		
		for (int i = 1; i < records.Count; i++) {
			// create the file
			string outfile = records[i][attributes["ID"]] + ".txt";
			StreamWriter output = new StreamWriter(outfile);
			StreamReader template = new StreamReader(templateFileName);
			
			while (!template.EndOfStream) {
				// get the template line
				//string[] toks = template.ReadLine().Split(' ');
				string[] toks = template.ReadLine().Split(new char[] {' ', '\t'});

				for (int j = 0; j < toks.Length; j++) {
					int tagBeginIdx = toks[j].IndexOf("<<");			
					if (tagBeginIdx >= 0) {
						//replace the tag with the appropriate parameter
						int tagEndIdx = toks[j].IndexOf(">>") + 1;
						string before = toks[j].Substring(0, tagBeginIdx - 0);
						string after = toks[j].Substring(tagEndIdx + 1, toks[j].Length - tagEndIdx - 1);
						string tagName = toks[j].Substring(tagBeginIdx + 2, tagEndIdx - tagBeginIdx - 3);
						
						toks[j] = before + records[i][attributes[tagName]] + after;
					}
		
				}
				foreach (string s in toks) {
					//Console.Write(s + " ");
					output.Write(s + " ");	
				}
				//Console.WriteLine();
				output.WriteLine();
			}
			output.Close();

		}	
	}

	public static void Main(string[] args) {
		StreamReader inputCsv = new StreamReader(args[0]);

		List<string[]> records;
		getRecords(inputCsv, out records);		
		writeRecords(records, args[1]);
		Console.WriteLine("Done.");
	}
}
}
