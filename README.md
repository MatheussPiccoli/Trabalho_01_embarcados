# Sensor de Proximidade com Arduino

Este projeto foi desenvolvido como parte da disciplina de Sistemas Embarcados. O sistema utiliza um sensor ultrassônico para detectar a proximidade de objetos e fornece feedback visual e sonoro de acordo com a distância medida.

## Funcionamento

O comportamento do sistema é baseado na distância entre o sensor e um objeto:

- **Quanto mais próximo o objeto estiver**, menor será o intervalo entre os sons emitidos pelo buzzer.
- **Quanto mais próximo o objeto estiver**, maior será a quantidade de LEDs acesos.
- Um **potenciômetro** permite ao usuário ajustar a distância máxima considerada pelo sensor.

## Componentes Utilizados

- Arduino Uno
- Sensor ultrassônico HC-SR04
- Buzzer
- 5 LEDs
- 5 resistores para os LEDs
- 1 potenciômetro
- Protoboard
- Jumpers

## Estrutura do Repositório

```text
.
├── sensorarduino.ino          # Código-fonte do Arduino
└── prototipo.png        # Esquema do circuito montado

Como Executar

Clone este repositório:

git clone https://github.com/MatheussPiccoli/Trabalho_01_embarcados.git
Abra o arquivo .ino na Arduino IDE.
Monte o circuito conforme o arquivo prototipo.png.
Faça o upload do código para o Arduino Uno.
Lógica do Sistema

O sensor HC-SR04 mede continuamente a distância até um objeto.

Com base nessa distância:

O buzzer emite sons em intervalos cada vez menores conforme o objeto se aproxima.
Os LEDs acendem progressivamente para indicar visualmente o nível de proximidade.
O potenciômetro ajusta a distância máxima de detecção.
Imagem do Protótipo

Objetivo do Projeto

Este projeto teve como objetivo aplicar conceitos de sistemas embarcados, leitura de sensores, controle de atuadores e processamento de sinais analógicos.

Além disso, foi uma oportunidade para retomar conhecimentos adquiridos anteriormente em Engenharia Elétrica.

Autor

Matheus Piccoli
