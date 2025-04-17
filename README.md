<h1 align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Montserrat&weight=600&pause=1000&color=2E68DF&center=true&vCenter=true&repeat=false&width=434&height=49&lines=Welcome%F0%9F%91%8B;This+is+the+first+Cp+by+Edge+Computing+%F0%9F%A4%98+"/>
</h1>

## 📝 Descrição do Projeto
<p>
    Desenvolvemos um circuito eletrônico para monitoramento de luminosidade ambiental destinado à Vinheiria Agnello. O sistema garante os níveis ideais de iluminação em adegas de vinho, preservando a qualidade das garrafas através de:
</p>
<ul>
    <li>Indicação visual com LEDs (verde/amarelo/vermelho)</li>
    <li>Alerta sonoro quando fora da faixa ideal</li>
    <li>Monitoramento contínuo via sensor LDR</li>
</ul>

<h2 align="left">🖥️ Circuito</h2>
<div align="center">
    <img src="./assets/circuito.png" width="40%">
</div>

<h2 align="left">🔌 Conexões Físicas - Passo a Passo</h2>

<div style="display: flex; justify-content: space-between; align-items: flex-start; gap: 40px;">
    <section style="flex: 1;">
        <h3 style="font-size: 16px; margin-bottom: 15px;">📦 Lista de Componentes</h3>
        <ul style="list-style-type: none; font-size: 16px; padding-left: 0;">
            <li style="margin-bottom: 8px;">• 1x Arduino Uno R3</li>
            <li style="margin-bottom: 8px;">• 1x Protoboard 400 pontos</li>
            <li style="margin-bottom: 8px;">• 1x Fotoresistor (LDR)</li>
            <li style="margin-bottom: 8px;">• 1x Buzzer passivo</li>
            <li style="margin-bottom: 8px;">• 1x Resistor 10 kΩ</li>
            <li style="margin-bottom: 8px;">• 3x Resistores 220 Ω</li>
            <li style="margin-bottom: 8px;">• 3x LEDs (verde, amarelo, vermelho)</li>
            <li style="margin-bottom: 8px;">• 13x Jumpers macho-macho</li>
        </ul>
    </section>
    <section style="flex: 2;">
        <h3 style="font-size: 18px; margin-bottom: 15px;">📌 Instruções de Montagem</h3>
        <ol style="font-size: 16px; padding-left: 20px;">
            <li style="margin-bottom: 20px;">
                <strong>Alimentação Básica:</strong><br>
                Conecte um jumper do pino 5V do Arduino ao barramento positivo da protoboard e outro jumper do pino GND ao barramento negativo.
            </li>
            <li style="margin-bottom: 20px;">
                <strong>Conexão dos LEDs:</strong><br>
                Para cada LED: conecte o ânodo (perna maior) ao barramento positivo via resistor de 220 Ω, e o cátodo (perna menor) aos pinos digitais 11 (vermelho), 12 (amarelo) e 13 (verde).
            </li>
            <li style="margin-bottom: 20px;">
                <strong>Sensor LDR:</strong><br>
                Ligue um terminal do LDR ao barramento positivo. No outro terminal, conecte o resistor de 10 kΩ em série com o barramento negativo, e uma ligação ao pino analógico A0 para leitura.
            </li>
            <li style="margin-bottom: 20px;">
                <strong>Buzzer:</strong><br>
                Conecte o terminal positivo ao pino digital 9 e o negativo ao barramento GND.
            </li>
        </ol>
    </section>
</div>

<h2 align="left">⚙️ Funcionamento</h2>
<p>
    O sistema opera através da leitura analógica do LDR (54-974), onde:<br>
    • LED Verde: Valores abaixo de 740 (luminosidade ideal)<br>
    • LED Amarelo: Entre 740-900 (atenção)<br>
    • LED Vermelho: Acima de 900 + buzzer por 3s + alerta de emergência (crítico)<br>
</p>
