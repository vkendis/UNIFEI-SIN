const geraEquacao = document.querySelector('#idAreaEquacao');
const btnGerar = document.querySelector('#btnGerarQ');
const btnValidar = document.querySelector('#btnValidarRes'); 
const resposta = document.querySelector('#resposta');
const areaValida = document.querySelector('#idAreaResp');
const fundo = document.querySelector('body');

let resultadoAtual = 0; 

btnGerar.addEventListener('click', () => {
    const num1 = Math.floor(Math.random() * 10);
    const num2 = Math.floor(Math.random() * 10);
    const operacao = Math.floor(Math.random() * 4);

    let operador = '';

    switch (operacao) {
        case 0:
            operador = '+';
            resultadoAtual = num1 + num2;
            break;
        case 1:
            operador = '-';
            resultadoAtual = num1 - num2;
            break;
        case 2:
            operador = '*';
            resultadoAtual = num1 * num2;
            break;
        case 3:
            operador = '/';
            if (num2 === 0) {
                num2 = 1; 
            }
            resultadoAtual = num1 / num2;
            break;
    }
    
   
    resultadoAtual = parseFloat(resultadoAtual.toFixed(2));

    geraEquacao.textContent = `${num1} ${operador} ${num2}`;
    resposta.value = ''; 
    areaValida.textContent = ''; 
});

btnValidar.addEventListener('click', () => {
    const respostaUsuario = parseFloat(resposta.value);

    if (isNaN(respostaUsuario)) {
        areaValida.textContent = "Por favor, insira um número válido.";
        areaValida.style.color = 'Red'; 
        fundo.style.backgroundColor = 'White'; 
    } else if (parseFloat(respostaUsuario.toFixed(2)) === parseFloat(resultadoAtual.toFixed(2))) {
        areaValida.textContent = "Parabéns!"; 
        areaValida.style.color = 'Green'; 
        fundo.style.backgroundColor = 'Green'; // Adicionei ao "fundo" para alterar para cor vermelha caso erre
    } else {
        
        areaValida.textContent = `Deu ruim, a Resposta correta é: ${resultadoAtual.toFixed(2)}`;
        areaValida.style.color = 'Red'; 
        fundo.style.backgroundColor = 'Red'; // Adicionei ao "fundo" para alterar para cor vermelha caso erre
    }
});

