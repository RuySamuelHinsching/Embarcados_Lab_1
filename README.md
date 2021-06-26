# Embarcados_Lab_1
Depois de ter verificado a temporização por
laços de atraso, teste o comportamento do
sistema para as seguintes alterações:
1. Diferentes níveis de otimização do compilador C
2. Frequência de clock (PLL) de 120MHz
• Há variações na temporização por software
para os casos acima? Quantifique-as.

R: Sim, dada a estrutura do programa com dois loops aninhados o número de operações realizadas nestes loops em assembly na configuração de otimização do compilador em low é 3*loop*2*loop. Assim, com o valor na variável loop = 1000, o número de ciclos de clock despendidos nestes loops aninhados será de 6000000 (6 milhões), então a transição de estado do led ocorre a cada 0,25 s então para obter um valor de transição de 1 segundo foi colocado o valor de 2000 na variável loop.
Na configuração de otimização do compilador de nível médio o teste condicional do loop mais interno é pulado então a conta passa a ser 2*loop*2*loop, assim a transição passa de 1 segundo para 0,66 s pois o número de iterações despendidas nos loops será de 16 milhões.
Na configuração de otimização do compilador em nível alto os loops são passados e as transições dos leds ocorrem a cada 3 instruções em assembly, ou seja, aproximadamente a cada 125 nanossegundos, dado que o clock do microcontrolador é de 24MHz.
Estando na configuração de otimização do compilador em nível low e mudando o clock de 24 MHz para 120 MHz, as transições de estado do led ocorrem a cada 0,2 segundos.

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
