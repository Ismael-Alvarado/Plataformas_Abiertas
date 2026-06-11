#i n c l u d e <s t d i o . h>
#i n c l u d e < s t d l i b . h>
3
4
/∗
5
6
Lee una imagen PGM ( formato P2 ) d e s d e un a r c h i v o .
Reserva memoria dinamica para l o s p i x e l e s .
7
8
9
10
11
12
Params :
− const char ∗ filename
− i n t ∗ width
− int ∗ height
− i n t ∗max_val
:
:
:
:
ruta del
donde s e
donde s e
donde s e
archivo .
guarda e l ancho l e i d o .
guarda e l a l t o l e i d o .
guarda e l v a l o r maximo .
13
Retorno :
− Puntero a l a r r e g l o de p i x e l e s , o NULL s i hubo e r r o r .
16 ∗/
17 u n s i g n e d c h a r ∗read_pgm ( c o n s t c h a r ∗ f i l e n a m e ,
18
i n t ∗ width , i n t ∗ h e i g h t , i n t ∗max_val ) {
19 }
14
15
20
21
22
23
24
/∗
A p l i c a un umbral T a l a r r e g l o de p i x e l e s i n _ p l a c e .
Usa unicamente a r i t m e t i c a de p u n t e r o s .
P i x e l e s >= T pasan a 2 5 5 ; e l r e s t o a 0 .
25
Params :
− u n s i g n e d c h a r ∗ p i x e l s : a r r e g l o de p i x e l e s a m o d i f i c a r .
28
− int total
: numero t o t a l de p i x e l e s .
29
− int threshold
: v a l o r d e l umbral T .
30 ∗/
31 v o i d a p p l y _ t h r e s h o l d ( u n s i g n e d c h a r ∗ p i x e l s ,
32
int total , int threshold ) {
33 }
26
27
34
35
/∗
36
37
38
Genera e l n e g a t i v o de un a r r e g l o de p i x e l e s en un nuevo a r r e g l o .
Reserva memoria dinamica para e l r e s u l t a d o .
Usa unicamente a r i t m e t i c a de p u n t e r o s .
39
40
41
42
Params :
− unsigned char ∗ p i x e l s : a r r e g l o fuente .
− int total
: numero t o t a l de p i x e l e s .
43
Retorno :
− Nuevo a r r e g l o con e l n e g a t i v o , o NULL s i f a l l o m a l l o c .
46 ∗/
47 u n s i g n e d c h a r ∗ make_negative ( u n s i g n e d c h a r ∗ p i x e l s ,
int total ) {
48 }
44
45
49
50
/∗
51
E s c r i b e un a r r e g l o de p i x e l e s como imagen PGM ( formato P2 ) .
52
Params :
− const char ∗ filename
55
− unsigned char ∗ p i x e l s
56
− i n t width
57
− int height
58
− i n t max_val
59 ∗/
60 v o i d write_pgm ( c o n s t c h a r
61
i n t width ,
62 }
53
54
:
:
:
:
:
r u t a d e l a r c h i v o de s a l i d a .
a r r e g l o de p i x e l e s .
ancho de l a imagen .
a l t o de l a imagen .
v a l o r maximo ( t i p i c a m e n t e 2 5 5 ) .
∗ filename , unsigned char ∗ p i x e l s ,
i n t h e i g h t , i n t max_val ) {
63
64
65
66
/∗
C a l c u l a e imprime e s t a d i s t i c a s d e l a r r e g l o o r i g i n a l y
d el a r r e g l o umbralizado .
67
68
Params :
− unsigned char ∗ o r i g i n a l
: a r r e g l o a n t e s d e l umbral .
− u n s i g n e d c h a r ∗ t h r e s h o l d e d : a r r e g l o d e s p u e s d e l umbral .
71
− int total
: numero t o t a l de p i x e l e s .
72 ∗/
73 v o i d p r i n t _ s t a t s ( u n s i g n e d c h a r ∗ o r i g i n a l ,
74
unsigned char ∗ thresholded , i n t t o t a l ) {
75 }
69
70
76
i n t main ( v o i d ) {
i n t width , h e i g h t , max_val , t h r e s h o l d ;
79
unsigned char ∗ p i x e l s
= NULL;
80
u n s i g n e d c h a r ∗ n e g a t i v e = NULL;
77
78
81
/∗ El e s t u d i a n t e completa . ∗/
82
83
return 0;
84
85
}