# Modelagem-Computacional
Projetos de Modelagem Computacional, em Linguagem C ( Projetil, Redes Tróficas, Disseminação de Doenças...)

PROJETO 01 => Lançamento de Projétil

Introdução 
O lançamento oblíquo é uma junção de movimentos na vertical e horizontal. Ocorre quando o objeto lançado forma um determinado ângulo 
com a horizontal. Nesse tipo de lançamento, o objeto executa dois movimentos simultâneos, ao mesmo tempo em que executa um movimento 
na vertical, subindo e descendo, também se desloca horizontalmente. 
 
 Objetivo 
O objetivo desta modelagem computacional consiste em criar um modelo matemático do fenômeno queda livre, para modela-lo usando 
programação tendo como objetivo simular e prever deslocamento e velocidade do objeto.  

PROJETO 02 => Redes Tróficas

Introdução  
 
O conceito de rede trófica, também conhecida como teia alimentar, é aplicado ao fenômeno natural em que diferentes seres vivos se conectam
entre si a partir do ciclo da vida que envolve que uns se alimentem dos outros para sobreviver. A palavra trófica provém do idioma grego, 
na qual "trophos" significa alimento. Assim, uma rede ou cadeia trófica é a união de diferentes elos que se unem pelo consumo para 
sobreviver. 

A rede trófica tem vários pontos que se repetem em todos os casos embora com variantes. O princípio de toda rede ou cadeia trófica trata
dos vegetais. Estes seres vivos, ao serem autótrofos, ou seja, ao produzir seu próprio alimento, são os primeiros elos na cadeia, 
pois outros seres vivos dependem deles para poder alimentar-se. As plantas e vegetais são autótrofos, pois apresentam elementos 
naturais como a água, a luz ou o dióxido de carbono para transformá-los em alimentos processados em seu interior. Assim, os vegetais, 
ao viver por seus próprios meios, permitem que os animais herbívoros possam alimentar-se também e seguir sobrevivendo. 
Os herbívoros costumam ser o segundo elo de toda rede trófica, pois são aqueles que consomem as plantas, razão pela qual devem estar
localizados num lugar imediatamente posterior. Estes animais são seguidos pelos animais carnívoros, aqueles que se alimentam de carne, 
então, os animais exclusivamente carnívoros estão localizados no terceiro posto, embora uma cadeia trófica possa apresentar vários elos
de carnívoros. 
 
Objetivo 
Neste trabalho tivemos o objetivo de expor o procedimento padrão utilizando as equações logísticas para cada indivíduo de uma rede
trófica previamente determinada considerando também a capacidade total de suporte do meio para o produtor, e as relações dos indivíduos
dessa cadeia variando determinadas constantes relacionadas às taxa de mortalidade e natalidade, a fim de encontrar uma combinação que
satisfaça uma simulação desse ambiente em um estado de equilíbrio. 
Nas simulações, foram utilizadas apenas relações de predatismo, com um produtor que cresce em quantidade a partir de uma taxa 
pré-definida. Assim como a taxa de crescimento do produtor, todas as outras taxas e parâmetros são pré-estabelecidas, 
e seu comportamento analisado. 


PROJETO 03 =>Sincronização de Neurônios

Introdução  
A Neurociência é a área que se ocupa em estudar o sistema nervoso, visando desvendar seu funcionamento, estrutura, desenvolvimento 
e eventuais alterações que sofra. Portanto, a utilização de técnicas de Modelagem Computacional na simulação da rede de neurônios do
ser humano se torna imprescindível no estudo e desenvolvimento dessa área da ciência. 
 
 
 Objetivo 
O seguinte trabalho possui o intuito de apresentar as etapas e o processo da modelagem do comportamento dos neurônios na manifestação de
sinapses, no cérebro humano. Uma vez que os neurônios se comunicam através de neurotransmissores pela fenda sináptica, um modelo
matemático adequado para a sua representação se utilizaria de grafos, de modo que as arestas representem as sinapses. 
Esse projeto possui por finalidade a visualização da oscilação e possível sincronização dos neurônios em dois tipos de topologias 
de rede: rede regular (grau 2), rede aleatória, há última, tem grau médio 2, que serão conceituadas mais adiante.


PROJETO 04 =>Topologia de redes em propagação de doenças

Introdução 
 
Propagações de doenças são assuntos recorrentes nos últimos anos. A capacidade de realizar previsões sobre o processo de disseminação
de doenças em determinados locais e populações poderia permitir a realização de processos de imunização passivas, isolamento e contenção
da enfermidade, por partes dos governos locais. 
 
 
 Objetivo 
 
O trabalho tem como objetivo estudar o processo de modelagem e a simulação de alguns casos e situações genéricas na propagação de 
doenças em populações. Com o intuito de expor o desenvolvimento do procedimento a ser aplicado, o modelo e os parâmetros utilizados 
serão descritos nas próximas seções. 
 
 
 Topologias de rede 
 As Topologias de rede são os padrões no qual um elemento de um determinado sistema se relaciona com o meio ou com outros elementos,
 normalmente essas topologias são representadas por grafos, onde os vértices correspondem aos próprios elementos, e as arestas 
 correspondem às relações ou interações que podem existir entre os vértices. No caso deste trabalho, os elementos correspondem aos 
 indivíduos de uma determinada população, e as arestas correspondem ao contato entre eles, fator que viabiliza a propagação de doenças
 no sistema. Neste estudo, foram simuladas propagações de doenças com diferentes probabilidades de infecção e recuperação, utilizando
 as redes regulares, aleatórias, livre de escala e modularizada. Uma rede regular possui uma distribuição de arestas uniforme, ou seja, 
 cada vértice possui aproximadamente o mesmo número de arestas. Para a rede aleatória, como o próprio nome sugere, possui uma 
 distribuição de arestas definida de modo aleatório. Com uma probabilidade uniforme de dois vértices possuírem uma aresta em comum. 
 Já uma rede livre de escala é a que segue uma lei de potência na distribuição de arestas, de modo que quanto mais arestas um vértice 
 possui, maior a chance de uma nova aresta ser inserida nele. Uma rede modularizada consiste em uma distribuição na densidade de arestas
 em regiões. Assim, existem regiões conexas, onde os vértices não possuem muitas arestas, e regiões fortemente conexas, onde existem 
 muitas arestas, podendo representar, por exemplo, grupos de pessoas que possuem forte contato entre si e fraco entre outros grupos. 
 
Modelo adotado 
 
O modelo matemático utilizado consiste numa adaptação estocástica do Modelo SIR, proposto W.O.kermack e A.G.mckendrick. 
As variáveis utilizadas serão semelhantes (dada uma doença e uma população, tem-se, na simulação, o número de indivíduos suscetíveis a 
contrair a doença, de infectados, recuperados e os que falecem em detrimento da doença, sendo que todos apresentados variam em função 
do tempo devido a interação da população dada pela topologia), porém o controle dessas variáveis ocorrerá através de duas 
probabilidades, a chance de um indivíduo contrair a doença em contato com um infectado, e a chance de um infectado se recuperar ou
morrer. Um modelo de simulação discreto se constitui de um sistema que depende de variáveis que assumem valores discretos, ou seja, 
valores finitos ou enumeráveis. Esse é o caso do modelo adotado, uma vez que os indivíduos só podem assumir quatro estados: suscetível 
à doença, infectado, morto ou recuperado, sendo que este último ao assumir tal estado não interfere mais na rede, pois adquiri 
resistência a doença.





 
