(define A "xyz")
(define B "xyz")

(newline)
(display "=")
(newline)
(display (= 3 4))          ; #f
(newline)
(display (= 7 (+ 3 4)))   ; #t
(newline)
;(display (= "abc" "abc"))  ; error

(display "EQ?")
(newline)
(display (EQ? "abc" "abc"))      ; #f
(newline)
(display (EQ? (car '(1 2 3)) 1)) ; #t
(newline)
(display (EQ? '(1 2 3) '(1 2 3))) ; #f
(newline)
(display (EQ? 0 0)) ; #t
(newline)
(display (EQ? 3.4 3.4)) ; #f
(newline)
(display (EQ? 3.4 (+ 3 0.4))) ; #f
(newline)

(display "EQV?")
(newline)
(display (EQV? 0 0)) ; #t
(newline)
(display (EQV? 3.4 3.4)) ; #t
(newline)
(display (EQV? 3.4 (+ 3 0.4))) ; #t
(newline)
(display (EQV? A A))		; #t
(newline)
(display (EQV? A B))		; #f
(newline)


(display "EQUAL?")
(newline)
(display (EQUAL? "abc" "abc"))      ; #t
(newline)
(display (EQUAL? (car '(1 2 3)) 1)) ; #t
(newline)
(display (EQUAL? '(1 2 3) '(1 2 3))) ; #t
(newline)
(display (EQUAL? A A))		; #t
(newline)
(display (EQUAL? A B))		; #t
(newline)
,exit
