# gs1-monitoramento-missao-espacial

-Pedro de Paula Ferreras RM: 568713
-Pedro Henrique Santos RM: 571017

O programa é estruturado em um loop principal DO-WHILE que mantém o sistema rodando até o usuário escolher encerrar. Dentro do loop, um menu é exibido e a opção digitada é processada via SWICTH.
Os dados coletados (temperatura, energia e comunicação) são armazenados em vetores globais de até 10 posições, permitindo um histórico de leituras. Um contador TOTAL_LEITURAS controla quantas leituras foram registradas.
As funcionalidades são divididas em funções separadas:

INSERIR_DADOS() valida se o limite de leituras foi atingido antes de solicitar os dados ao usuário, garantindo que os vetores não sejam ultrapassados.
VISUALIZAR_STATUS() exibe o histórico completo em formato de tabela e chama VERIFICAR_ALERTAS() para a leitura mais recente.
EXECUTAR_ANALISE() percorre todas as leituras registradas em um loop for e chama VERIFICAR_ALERTAS() para cada uma delas.
VERIFICAR_ALERTAS(i) analisa a leitura no índice i contra três condições críticas: temperatura acima de 80°C, energia abaixo de 20% e falha de comunicação. Se nenhuma condição for ativada, exibe status normal.

O terminal é limpo com system("cls") antes de cada ação e system("pause") pausa a execução para o usuário ler o resultado antes de voltar ao menu.
