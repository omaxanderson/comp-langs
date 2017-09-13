% cut.pl
% CUT !
% GOAL: a, b, !, c, d
% once a and b are satisfied, the satisfiability of the goal depends
% only on c and d. That is, the subgoals, a and b will not be reevaluated.
% Done for efficiency reasons.

member2(E, [E | _]).
member2(E, [_ | L]) :- member2(E, L).

member3(E, [E | _]) :- !.
member3(E, [_ | L]) :- member3(E, L).

% useful in generate and test strategy.
% generator example from Sebesta.

is_integer(1).
is_integer(X) :- is_integer(Y), X is Y + 1.

divide(N1, N2, RES) :- is_integer(RES), 
	     PROD1 is RES * N2,
	     PROD2 is (RES + 1) * N2,
	     PROD1 =< N1, PROD2 > N1, !.	% Cut after unique goal is found
