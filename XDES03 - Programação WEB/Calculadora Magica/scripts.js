let operation = '+';

function setOperation(op) {
    operation = op;
    document.getElementById('operator').innerText = op;
    highlightButton(op);
}

function highlightButton(op) {
    document.getElementById('btn-add').classList.remove('selected');
    document.getElementById('btn-subtract').classList.remove('selected');
    document.getElementById('btn-multiply').classList.remove('selected');

    switch (op) {
        case '+':
            document.getElementById('btn-add').classList.add('selected');
            break;
        case '-':
            document.getElementById('btn-subtract').classList.add('selected');
            break;
        case '*':
            document.getElementById('btn-multiply').classList.add('selected');
            break;
    }
}

function calculate() {
    const op1 = document.getElementById('op1').value;
    const op2 = document.getElementById('op2').value;

    if (op1 === '' || op2 === '') {
        alert('Operandos não podem ser vazios!');
        return;
    }

    const num1 = parseFloat(op1);
    const num2 = parseFloat(op2);
    let result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
    }

    document.getElementById('result').innerText = `Resultado: ${result}`;
}
