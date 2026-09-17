# What is GCD?
The $\gcd(a,b)$ function in math returns the **G**reatest **C**ommon **F**actor. If you want more information on these functions, you can take a look at [my notes](https://github.com/HighlyExistant/My-Notes) in the discrete math section. That said, here will be a quick summary of the thoughts that should go into implementing the algorithms here.
## Properties of the GCD
These offer good test cases:
* $\gcd(a,1)=1$
* $\gcd(a,b)\geq 1$
* $\gcd(a,b)=\gcd(|a|,|b|)$
* $\gcd(a,0)=|a|$
* $\gcd(ka,kb)=|k|\gcd(a,b)$
* for $a,b\in\mathbb{N}\wedge b>a\Rightarrow \gcd(b,b-a)=\gcd(b,b+a)$.
## GCD using Euclids Method
We'll be using this property of the $\gcd$:

If $a=bq+r$ with $0\leq r\leq b$, then $\gcd(a,b)=\gcd(b,r)$

By recursively getting the remainder like so, we can quickly reach our greatest common factor.