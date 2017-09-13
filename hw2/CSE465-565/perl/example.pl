#!/usr/bin/perl
#perl is freeformat
#scalar variables: $[letter][letter|uscore|digit]*

print("Enter your name:");
$name = <STDIN>;
chop($name);   # chop removes last character of input
$greeting1 = "\LHELLO\E THERE $name";	# hello THERE Fred
$greeting2 = '\LHELLO\E THERE $name';	# \L HELLO\E THERE $name
print($greeting1, "\n");  # \t, \U, ...
print($greeting2, "\n");


@arr = (0, "hello", 2..10);	# zero based indices
@arr[2] = "another string";
@arr[4..7] = (-1,-2,-3,-4);	# array slice
foreach $x (@arr) {
		print($x . "\n");
}

# sort, reverse
@words = split(/ /, "once upon a time\n");
print("@words");

# equivalently
for ($i=0; $i<@arr; $i++) {
		print(@arr[$i] . "\n");
}

print("Enter a small number (< 12):");
$target = <STDIN>;
chop($target);		# can be problems if non-number is entered
$n = 0;
$sum = 0;

while ($sum < $target) {   # {} needed
		$n++;
			$sum += 1 / $n;	# compound assignments
}
#until, for, foreach, do-while, do-until
#last can be used to exit out of a non-do loops
#next can be used to start next iteration
#restart can be used to restart a loop

if ($n < 50) {
		print("only a few summations were needed: ", $n);
} elsif ($n < 1000) {
		print("a moderate number of summations were needed: ", $n);
} else {
		print("a lot of summations were needed: ", $n);
}

print("\n");

# arithmetic ops: *, +, -, /, **
# numeric compare: >, <, >=, <=, ==, !=, <=> (+1, 0, -1)
# string compare: lt, gt, eq, le, ge, ne, cmp (+1, 0, -1)
# &&, ||, !, or, and, not, xor (short-circuited)
# . string concat
# x string repetition
# condition expression ?:

$s1 = "hello";
$s2 = "world";
if ($s1 == $s2) {	# true! why?
		print("equal\n");
} else {
		print("not equal\n");
}
