from Fraction import Fraction

class Problem:
    def __init__(self, f1, f2, op):
        self.fraction1 = f1
        self.fraction2 = f2
        self.operation = op
        
    def __str__(self):
        return "%s %s %s" % (self.fraction1, self.operation, self.fraction2)    
    
    def answerCorrect(self, ans):
        if self.operation == "+":
            return ans == self.fraction1 + self.fraction2
        elif self.operation == "-":
            return ans == self.fraction1 - self.fraction2
        elif self.operation == "*":
            return ans == self.fraction1 * self.fraction2
        elif self.operation == "/":
            return ans == self.fraction1 / self.fraction2

if __name__ == "__main__":
    f1 = Fraction(1, 2)
    f2 = Fraction(-25, -100)
    prob = Problem(f1, f2, "-")
    print(prob)
    answer = Fraction(1, 8)
    if prob.answerCorrect(answer):
        print("the answer is correct")
        print("%s = %s" % (prob, answer))
    else:
        print("the answer is NOT correct")
        print("%s != %s" % (prob, answer))
