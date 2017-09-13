; basics.scm
; From within Scheme interpreter: (load "basics.scm")

(define COST 10)

(define (demo)
	(DISPLAY (+ 2 3))
	(NEWLINE)
	(DISPLAY (ACOS -1.0))
	(NEWLINE)
	(DISPLAY (ABS -232))
	(NEWLINE)
	(DISPLAY (+ (* 2 4) 3))
	(NEWLINE)
	(DISPLAY (+ (* 2 4) 3))
	(NEWLINE)
	#t
)

(DISPLAY ((lambda (x y) (* x y)) 4 5))
;;; Write lambda expression for computing the perimeter of a rectangle, given its length and width as parameters

(define (mycube x) (* x x x))

(define (sqr x) (* x x))

(define (hyp s1 s2) 
	(sqrt (+ (sqr s1) (sqr s2)))
)

(define (logbase x base)
	(/ (log x) (log base))
)

(define (distance x1 y1 x2 y2)
;;; FILL THIS IN
	0
)

(define (perimeter L W)
	(* 2 (+ L W))
)

;;;; some predicates and relational operators: >= > < <= = EVEN? ODD? ZERO? AND OR

(define (max a b)
	(if (> a b) a b)
)

(define (isSmall x)
;;; FILL THIS IN
	0
)

(define (fib n)
	(cond
		((= n 1) 1)
		((= n 2) 1)
		(else (+ (fib (- n 1)) (fib (- n 2))))
	)
)

(define (isInQuadrant1 x y)
;;; FILL THIS IN
	0
)

(define (quadrant x y)
;;; FILL THIS IN
	0
)

(define (computeGrossPay hours rate)
;;; FILL THIS IN
;;; Hours over 40 are given time and half. Hours over 60 are given double time.
	0
)
