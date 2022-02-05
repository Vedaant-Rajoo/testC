# GCD of an array

You are given an array $a$ of length $n$. You are asked to process $q$ queries of the following format: given integers $i$ and $x$, multiply $a_i$ by $x$.

After processing each query you need to output the greatest common divisor (GCD) of all elements of the array $a$.

Since the answer can be too large, you are asked to output it modulo $10^9+7$.

## Input
```
4 3
1 6 8 12
1 12
2 3
3 3
```
## Output
```
2
2
6
```
## Explanation
$\operatorname{gcd}(12, 6, 8, 12) = 2 \\$ 
$\operatorname{gcd}(12, 18, 8, 12) = 2 \\$
$\operatorname{gcd}(12, 18, 24, 12) = 6$