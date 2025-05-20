# Sistema de Irrigação Automático – Mata Atlântica

## Descrição
Este projeto é um sistema automatizado de irrigação para plantas, com foco na Mata Atlântica. Utiliza sensores para monitorar a umidade do solo e as condições do ar, acionando uma bomba de água quando necessário.

O sistema também exibe informações em um display LCD 16x2, alternando a cada 15 segundos entre a umidade do solo e a temperatura ambiente.

## Componentes Utilizados
- Arduino (Nano, Uno ou similar)

- Sensor de umidade do solo capacitivo (pino A0)

- Sensor DHT22 para temperatura e umidade do ar (pino A1)

- Relé para controle da bomba de água (pino 7)

- Display LCD 16x2 (pinos 8 a 13)

## Funcionalidades
- Mede a umidade do solo e mapeia para porcentagem

- Mede umidade e temperatura do ar com DHT22

- Aciona bomba automaticamente conforme condições definidas

- Exibe dados e status no display LCD

- Alterna a cada 15 segundos entre mostrar umidade do solo + ar e temperatura

## Uso
- Conecte os sensores e relé conforme os pinos do código.

- Faça upload do código para seu Arduino.

- O sistema começa a monitorar e controlar a irrigação automaticamente.

- Veja as informações no LCD.

## Detalhes Técnicos
- O sensor de umidade do solo é lido via entrada analógica A0.

O sensor DHT22 usa a biblioteca DHT para leitura.
- 
- A bomba é acionada via relé ativo em HIGH no pino 7.

- LCD usa a biblioteca LiquidCrystal com interface paralela.

- Código alterna a exibição da linha 2 do LCD entre umidade e temperatura a cada 15 segundos.

## Autor
## Feito por luizeduos
