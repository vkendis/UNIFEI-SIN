let randomNumber;
let attempts = 0;

document.getElementById('pensar-btn').addEventListener('click', () => {
    const inicio = parseInt(document.getElementById('inicio').value);
    const fim = parseInt(document.getElementById('fim').value);
    const messageElement = document.getElementById('message');
    const guessMessageElement = document.getElementById('guess-message');

    guessMessageElement.innerHTML = '';
    attempts = 0;

    if (isNaN(inicio) || isNaN(fim) || inicio < 0 || fim < 0 || fim <= inicio) {
        messageElement.innerHTML = 'Digite um número inteiro nos campos "início" e "fim"!';
    } else {
        randomNumber = Math.floor(Math.random() * (fim - inicio + 1)) + inicio;
        messageElement.innerHTML = `Pronto! Pensei em um número entre ${inicio} e ${fim}. Tente Adivinhar.`;
        document.body.style.backgroundColor = ''; 
    }
});

document.getElementById('guess-btn').addEventListener('click', () => {
    const guess = parseInt(document.getElementById('guess').value);
    const messageElement = document.getElementById('message');
    const guessMessageElement = document.getElementById('guess-message');
    document.body.style.backgroundColor = 'yellow';

    if (randomNumber === undefined) {
        guessMessageElement.innerHTML = 'Calma Jovem! Nem pensei em nenhum número. Lembrou de clicar no "Pensar"?';
    } else if (isNaN(guess)) {
        guessMessageElement.innerHTML = 'Digite um número inteiro para tentar adivinhar o que pensei';
    } else {
        attempts++;
        if (guess < randomNumber) {
            guessMessageElement.innerHTML = 'Pensei em um valor maior.';
        } else if (guess > randomNumber) {
            guessMessageElement.innerHTML = 'Pensei em um valor menor.';
        } else {
            guessMessageElement.innerHTML = `Parabéns! Você acertou o número ${randomNumber} após ${attempts} tentativas.`;
            document.getElementById('inicio').value = '';
            document.getElementById('fim').value = '';
            document.getElementById('guess').value = '';
            document.body.style.backgroundColor = 'green';
            randomNumber = undefined;
        }
    }
});
