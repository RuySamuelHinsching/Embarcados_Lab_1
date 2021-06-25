# Embarcados_Lab_1
Depois de ter verificado a temporização por
laços de atraso, teste o comportamento do
sistema para as seguintes alterações:
1. Diferentes níveis de otimização do compilador C
2. Frequência de clock (PLL) de 120MHz
• Há variações na temporização por software
para os casos acima? Quantifique-as.

R: Sim, conforme a otimização do compilador é incrementada
vários loops parecem ser otimizados e os cálculos internos dos loops
que duravam umas dezenas de milhares de ciclos são otimizados em 
poucas centenas de ciclos de clock. E conforme o clock é incrementado
a frequencia das operações é incrementada e portanto a troca do 
estado do led aumenta de frequencia.


Os seguintes trechos de código são
equivalentes:
– GPIOPinWrite(GPIO_PORTF_BASE,
GPIO_PIN_4, GPIO_PIN_4);
– GPIOPinWrite(0x40025000, 0x00000010,
0x00000010);
• Qual dos trechos de código acima é mais
legível e fácil de se compreender?

R: – GPIOPinWrite(GPIO_PORTF_BASE,
GPIO_PIN_4, GPIO_PIN_4);
Este código é mais fácil de se compreender pois 
é uma linguagem mais próxima do entendimento humano

Os seguintes trechos de código são
equivalentes:
– GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
GPIO_PIN_0 | GPIO_PIN_4);
– GPIOPinTypeGPIOOutput(0x40025000,
0x00000011);
• Qual dos trechos de código acima é mais
legível e fácil de se compreender?
• Obs: GPIO_PIN_0=0x01; GPIO_PIN_4=0x10

R:– GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
GPIO_PIN_0 | GPIO_PIN_4);
Este código é mais fácil de se compreender pois 
é uma linguagem mais próxima do entendimento humano
