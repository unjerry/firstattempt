# firstattempt
my first attempt to the git

maybe my final project will be called NoException NE
## this is a trial

When $a \ne 0$, there are two solutions to $(ax^2 + bx + c = 0)$ and they are 

$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a} $$

The Cauchy-Schwarz Inequality

$$\left( \sum_{k=1}^n a_k b_k \right)^2 \leq \left( \sum_{k=1}^n a_k^2 \right) \left( \sum_{k=1}^n b_k^2 \right)$$

## present version contain as follow

### mathtoolslibrary

#### complexnumber

function explanation
1. provide a class realize the complexnumber field
	
	include:

    1.commutative binary operation $+$ 

	$:(a,b)\rightarrow c=a+b,(a,b)=(b,a),\forall a,b,c\in\mathbb{C}$

	2.commutative binary operation $*$ 

	$:(a,b)\rightarrow c=a\times b,(a,b)=(b,a),\forall a,b,c\in\mathbb{C}$

	3.binary operation ^ 

	$:(a,b)\rightarrow c=a^b,\forall a,b,\in\mathbb{C}$

	identity tell $=$

	$$ \begin{equation}(a,b)=\left\{ \begin{aligned}1 \quad a=b\\0 \quad a\neq b\\\end{aligned}\right.\end{equation}
	$$

	$$
	\begin{cases}
	1  a=b \\ 
	0  a \neq b 
	\end{cases}
	$$

	$$ F^{HLLC}=\{ sdf\\sdf$$

	$$ A_{1b} = \left[\begin{array}{ccc} 1 & 0 & 0 \\ -D & 1 & 0 \\ 0 & 0 & 1 \end{array} \right] $$ 



2. realize standard input output

	complex.output(FILE *f,int opt)
	complex.input(FILE *f,int opt)
	(a+bi)
	a, b is wait to change
	$a,b \in \mathbb{R}$

3. realization

	complexnumber.h(inline realization)

### mathtoolstemplate

#### fieldmatrix

function explanation
1. provide some basic matrix operatrions over any field $\mathbb{F}$
	
	include:

	1.matrix multipulication

	noncommutative binary operator *

	$:(A,B)\rightarrow C=AB,(A,B)\neq(A,B),\forall A,B\in\mathbb{F}^{n\times m},\exists C \in\mathbb{F}^{n\times m}$


#### numbertheoryalgorithm

1. extended_euclidean

	function prototype

	template \<class Z>
	Z extended_euclidean(Z a, Z b, Z &x, Z &y);

	function explanation

	it works steable on euclidean ring which $Z$ refer an euclidean ring

	it takes two ring element a,b and two position $x,y$

	gives back the common divisor $d$ of $a,b$

	$x,y$ fufill the linear reqresentaion $xa+yb=d$



### mathtools

#### discretefouriertransform

funtcion explanation
this piece of function takes a list of "complexnumber" a[N] as input & gives the a list b[N] of same length contains "complexnumber" as  output

the rule of this function follows:
a[i]=sum((b[k]/N)*zeta[i*k])(0<=k<=N-1)
where zeta[i]=e^((2PI*Im/N)*i)

### applianceprojects

####splitwave

a splitwave is a function takes a list of "complexnumber" a[N] as input and gives a list of list of "complexnumber" b[ceil(log2(N))][N] as output and the rule as follow


    
