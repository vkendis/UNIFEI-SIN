document.getElementById('adicionarProduto').addEventListener('click', function() {
    const nomeProduto = document.getElementById('nomeProduto').value;
    const quantidade = document.getElementById('quantidade').value;

    if (nomeProduto === '') {
        alert('Nome do produto não pode ser vazio');
        return;
    }

    const listaProdutos = document.getElementById('listaProdutos');
    const item = document.createElement('li');
    item.textContent = `${nomeProduto} - Quantidade: ${quantidade}`;

    const botaoRemover = document.createElement('button');
    botaoRemover.textContent = 'X';
    botaoRemover.addEventListener('click', function() {
        listaProdutos.removeChild(item);
    });

    item.appendChild(botaoRemover);
    listaProdutos.appendChild(item);

    document.getElementById('nomeProduto').value = '';
    document.getElementById('quantidade').value = '1';
});
