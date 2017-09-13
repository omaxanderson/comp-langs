#!/usr/bin/perl
sub getline {
	$line = <STDIN>;
}

sub total {
	my($line, $sum, $v);
	$line = <STDIN>;
	chop($line);
	@items = split(/ /, $line);
	$sum = 0;
	foreach $v (@items) {
		$sum += $v;
	}
	$retval = $sum;	# return($sum) also OK
}

sub addem {
	my($a, $b, $c) = @_;
	$retval = $a + $b + $c;
}

getline;   # need &getline if forward reference
print($line);
$total = total;
print($total . "\n");
print(addem(3, -2, 10) . "\n");

%age = ("jim", 16, "mitch", 5);
$age{"fred"} = 64;
$age{"betty"} = 67;
delete($age{"jim"});
$age{"jason"} = 22;
foreach $name (keys(%age)) {
	print("$name is $age{$name}\n");
}

$str = <STDIN>;
if ($str =~ /please/i) {
		print("you are polite\n");
}

# + 1 or more
# * 0 or more
# . any character
# ? zero or one
# [aeiouAEIOU] set
# [a-zA-Z] range
# [^aeiou] complement 

# ^ beginning of sting
# $ end of string

# \d same as [0-9]
# \D same as [^0-9]
# \s same as [\r\t\n\f] (whitespace)
# \S same as [^\r\t\n\f] (not whitespace)

