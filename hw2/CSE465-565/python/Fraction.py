def greatestCommonDivisor(a, b):
    if b == 0:
        return a
    else:
        return greatestCommonDivisor(b, a % b)


class Fraction:
    def __init__(self, n, d):
        self.num = n
        assert(d != 0)
        self.denom = d
        self.normalize()
        
    def reduce(self):
        gcd = greatestCommonDivisor(self.num, self.denom)
        self.num /= gcd
        self.denom /= gcd
        
    def normalize(self):
        if self.denom < 0:
            self.denom = -self.denom;
            self.num = -self.num;
        self.reduce()
        
    def reciprocal(self):
        assert(self.num != 0)
        return Fraction(self.denom, self.num)
    
    def __str__(self):
        return "%d/%d" % (self.num, self.denom)
    
    def __mul__(self, other):
        return Fraction(self.num*other.num, self.denom*other.denom);

    def __truediv__(self, other):
        return self * other.reciprocal()
    
    def __neg__(self):
        return Fraction(-self.num, self.denom)
    
    def __add__(self, other):
        n = self.num * other.denom + self.denom * other.num
        d = self.denom * other.denom
        return Fraction(n, d)
    
    def __eq__(self, other):
        return self.num == other.num and self.denom == other.denom
    
    def __sub__(self, other):
        return self + (-other)

if __name__ == "__main__":
    f1 = Fraction(1, 2)
    f2 = Fraction(-25, -100)
    print(f1)
    print(f2)
    print(f1*f2)
    print(f1/f2)
    print(f1-f2)
    print(f2-f1)
    print(f1+f2)
    print(f1 == f2)
    print(f1 == f1)

