# Sistema de Monitoramento de Umidade do Solo com Arduino

Este projeto simula um sistema de monitoramento de umidade do solo utilizando Arduino Uno, sensor de umidade, display LCD I2C e LEDs indicadores.

A proposta é representar, em ambiente de simulação no Tinkercad, um sistema simples de irrigação automática. O sensor realiza a leitura da umidade do solo e o Arduino interpreta esse valor, exibindo a porcentagem no LCD e acionando LEDs conforme o estado do solo.

## Funcionamento do Projeto

O sistema realiza a leitura analógica do sensor de umidade do solo e converte o valor para porcentagem.

A umidade é exibida no display LCD 16x2, junto com o estado atual do solo.

Além disso, o projeto utiliza LEDs para indicar visualmente a situação:

- LED vermelho: solo seco
- LED amarelo: solo médio
- LED azul: simulação da bomba de água ligada

Quando a umidade está baixa, o LED vermelho acende e o LED azul é ativado, representando o acionamento da bomba de irrigação.

## Componentes Utilizados

- Arduino Uno R3
- Sensor de umidade do solo
- Display LCD 16x2 I2C
- LED vermelho
- LED amarelo
- LED azul
- Resistores de 220 ohms
- Jumpers
- Protoboard
- Simulador Tinkercad

## Ligações do Sensor de Umidade

| Sensor de Umidade | Arduino Uno |
|-------------------|-------------|
| VCC               | 5V          |
| GND               | GND         |
| A0 / SIG          | A0          |
| D0                | Não utilizado |

## Ligações do LCD I2C

| LCD I2C | Arduino Uno |
|--------|-------------|
| GND    | GND         |
| VCC    | 5V          |
| SDA    | SDA         |
| SCL    | SCL         |

## Ligações dos LEDs

| Componente | Arduino Uno |
|-----------|-------------|
| LED vermelho | D8 |
| LED amarelo | D9 |
| LED azul | D10 |

Cada LED deve ser ligado em série com um resistor de 220 ohms.

## Lógica de Funcionamento

| Umidade | Estado do Solo | Ação |
|--------|----------------|------|
| Abaixo de 30% | Solo seco | Liga LED vermelho e LED azul |
| Entre 30% e 70% | Solo médio | Liga LED amarelo |
| Acima de 70% | Solo úmido | Desliga LEDs de alerta |

## Calibração do Sensor

Durante os testes, foram utilizados os seguintes valores de calibração:

| Condição | Valor Analógico |
|---------|-----------------|
| Solo seco | 1023 |
| Solo molhado | 318 |

Esses valores são utilizados para converter a leitura analógica do sensor em porcentagem de umidade.

## Objetivo do Projeto

O objetivo deste projeto é demonstrar o funcionamento básico de um sistema automatizado de monitoramento de umidade do solo.

Esse tipo de sistema pode ser aplicado em projetos de agricultura inteligente, hortas automatizadas, jardinagem e pequenos sistemas de irrigação.

## Possíveis Melhorias Futuras

- Adicionar um relé para acionar uma bomba de água real
- Implementar um botão para modo manual e automático
- Adicionar buzzer para alerta de solo seco
- Registrar a quantidade de vezes que a bomba foi acionada
- Utilizar ESP32 para enviar os dados por Wi-Fi ou Bluetooth
- Criar uma interface web para monitoramento remoto

## Objetivo

O sistema realiza a leitura da umidade, exibe os dados no display LCD e utiliza LEDs para representar os estados do solo e o acionamento da bomba.

### Autor

Guilherme Costa
