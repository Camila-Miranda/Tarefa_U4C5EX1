Sistema de Controle de LEDs com Temporizador - Raspberry Pi Pico

Descrição

Este programa implementa um sistema de controle de LEDs utilizando o microcontrolador Raspberry Pi Pico.
Ele utiliza um botão para ativar os LEDs e um temporizador para desligá-los progressivamente a cada 3 segundos.

Componentes Utilizados

*Microcontrolador: Raspberry Pi Pico
*LEDs: Azul (GPIO 11), Vermelho (GPIO 12), Verde (GPIO 13)
*Botão (Pushbutton): Conectado ao GPIO 5
*Resistores: 330Ω para cada LED

Funcionamento

1. O sistema inicia aguardando um acionamento do botão.
2. Quando o botão é pressionado:
    *Os três LEDs (azul, vermelho e verde) são acesos.
    *Um temporizador (add_alarm_in_ms()) inicia e, a cada 3 segundos, desliga um LED.
    *Após 9 segundos, todos os LEDs estarão apagados e o sistema poderá ser acionado novamente.
3O botão só pode ser pressionado novamente após todos os LEDs estarem desligados.

Como Compilar e Executar

Requisitos

*Ambiente de desenvolvimento: VS Code + extensão CMake Tools
*SDK do Raspberry Pi Pico: Deve estar instalado e configurado
*Compilador ARM: Necessário para gerar o binário para o Pico

Passos para Compilação

1. Clone este repositório:

git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio

2. Crie uma pasta de build e acesse-a:

mkdir build && cd build

3. Gere os arquivos de build com CMake:

cmake ..

4. Compile o código:

make

5. Conecte o Raspberry Pi Pico ao computador em modo BOOTSEL e arraste o arquivo .uf2 gerado para ele.

Execução no Raspberry Pi Pico

*Após carregar o binário no Raspberry Pi Pico, abra um terminal serial (exemplo: minicom ou PuTTY) e conecte-se à porta correta.
*O sistema imprimirá no terminal:
    Sistema aguardando acionamento do botão...
*Pressione o botão para ativar os LEDs e veja a sequência de desligamento progressivo.