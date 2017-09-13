from Problem import Problem
from Fraction import Fraction

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
