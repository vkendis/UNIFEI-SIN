document.addEventListener('DOMContentLoaded', () => {
    const productNameInput = document.getElementById('product-name');
    const incrementButton = document.getElementById('increment');
    const decrementButton = document.getElementById('decrement');
    const quantityDisplay = document.getElementById('quantity');
    const addButton = document.getElementById('add-button');
    const productItems = document.getElementById('product-items');
    const totalProducts = document.getElementById('total-products');

    let quantity = 1;
    let totalProductCount = 0;

    incrementButton.addEventListener('click', () => {
        quantity++;
        updateQuantityDisplay();
    });

    decrementButton.addEventListener('click', () => {
        if (quantity > 1) {
            quantity--;
            updateQuantityDisplay();
        }
    });

    addButton.addEventListener('click', () => {
        const productName = productNameInput.value.trim();
        if (!productName) {
            alert('Nome do produto não pode ser vazio');
            return;
        }
        
        addProductToList(productName, quantity);
        resetInputFields();
    });

    function updateQuantityDisplay() {
        quantityDisplay.textContent = quantity;
    }

    function addProductToList(name, quantity) {
        const li = document.createElement('li');
        li.textContent = `${name}. Quantidade: ${quantity}`;
        
        const removeButton = document.createElement('button');
        removeButton.textContent = 'X';
        removeButton.addEventListener('click', () => {
            productItems.removeChild(li);
            totalProductCount--;
            updateTotalProductCount();
        });

        li.appendChild(removeButton);
        productItems.appendChild(li);

        totalProductCount++;
        updateTotalProductCount();
    }

    function resetInputFields() {
        productNameInput.value = '';
        quantity = 1;
        updateQuantityDisplay();
    }

    function updateTotalProductCount() {
        totalProducts.textContent = `Total de Produtos: ${totalProductCount}`;
    }
});
