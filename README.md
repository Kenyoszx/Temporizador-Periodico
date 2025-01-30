# Semáforo com Temporizador Periódico
O código implementa o algoritmo que representa um semáforo que muda de estado a cada 3 segundos através de um contador periódico. O código foi projetado para plataforma educacional BitDogLab 6.3, mas também é compatível com o microcontrolador RP2040

## Funcionalidades

- Inicializa e controla três LEDs (vermelho, verde e azul) conectados a pinos específicos do Raspberry Pi Pico.
- A cada 3 segundos, um temporizador é acionado para alternar os LEDs em uma sequência cíclica (Vermelho → Azul → Verde → Vermelho).
- Durante o loop principal, uma mensagem é exibida no terminal a cada 1 segundo.

## Hardware Necessário

- 1 Raspberry Pi Pico W (rp2040).
- 3 LEDs (Vermelho, Azul, Verde).
- Resistores apropriados para os LEDs.
- Fios de conexão.

## Pinagem

- LED Vermelho: Pino GPIO 13
- LED Azul: Pino GPIO 12
- LED Verde: Pino GPIO 11

## Configuração do Ambiente

Antes de começar, certifique-se de que você tenha o ambiente de desenvolvimento do **Raspberry Pi Pico** configurado corretamente. Siga as instruções do [Raspberry Pi Pico SDK](https://www.raspberrypi.org/documentation/rp2040/getting-started/) para configurar o SDK e as ferramentas de compilação.

## Compilação e Upload

1. Compile o código usando o ambiente de desenvolvimento configurado.
2. Após a compilação, faça o upload do código para o seu **Raspberry Pi Pico**.

## Tecnologias Utilizadas

- **C/C++**
- **Raspberry Pi Pico SDK**

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir um problema ou enviar um pull request.
