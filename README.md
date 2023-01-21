# firstattempt
my first attempt to the git

maybe my final project will be called NoException NE
## present version contain as follow
### header file
#### complexnumber
function explanation
1. provide a class realize the complexnumber field
include:
commutative binary operation $+$ 
+$:(a,b)\rightarrow c=a+b,(a,b)=(b,a),\forall a,b,c\in\mathbb{C}$
commutative binary operation $*$ 
*$:(a,b)\rightarrow c=a\times b,(a,b)=(b,a),\forall a,b,c\in\mathbb{C}$
binary operation ^ 
^$:(a,b)\rightarrow c=a^b,\forall a,b,\in\mathbb{C}$
identity tell $=$
=$$
\begin{equation}
:(a,b)=\left\{
	\begin{aligned}
	1 \quad a=b\\
	0 \quad a\neq b\\
	\end{aligned}
	\right
	.
\end{equation}
$$
2. realize standard input output
complex.output(FILE *f,int opt)
### mathtools
#### discretefouriertransform
funtcion explanation
this piece of function takes a list of "complexnumber" a[N] as input & gives the a list b[N] of same length contains "complexnumber" as  output

the rule of this function follows:
a[i]=sum((b[k]/N)*zeta[i*k])(0<=k<=N-1)
where zeta[i]=e^((2PI*Im/N)*i)


    
