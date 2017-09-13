% relatives.pl

female(janet).
female(jennifer).
female(hannah).
female(abigail).

male(todd).
male(matt).
male(mitch).
male(mike).
male(phil).

father(mike, abigail).
father(mike, hannah).

father(todd, matt).
father(todd, mitch).

father(phil, jennifer).
father(phil, todd).
father(jim, phil).
mother(ann, jim).

mother(jennifer, abigail).
mother(jennifer, hannah).

mother(janet, matt).
mother(janet, mitch).

parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).

spouse(todd, janet).
spouse(janet, todd).
spouse(mike, jennifer).
spouse(jennifer, mike).

mthAncestor(O, O, 0).
mthAncestor(O, Y, M) :- M > 0, parent(O, X), M1 is M - 1, mthAncestor(X, Y, M1).

grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
siblings(X, Y) :- parent(Z, X), parent(Z, Y).			% why multiple answers?

altSiblings(X, Y) :- parent(Z, X), parent(Z, Y), not(X = Y).

cousin(X, Y) :- parent(A, X), parent(B, Y), altSiblings(A, B).
uncle(X, Z) :- male(X), altSiblings(X, Y), parent(Y, Z).
uncle(X, Z) :- male(X), spouse(X, Y), altSiblings(Y, W), parent(W, Z).
uncle2(X, Z) :- male(X), parent(X, W), cousin(W, Z).    % does this work?

ancestor(X, X).
%ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).
ancestor(X, Y) :- ancestor(Z, Y), parent(X, Z).		% problematic
