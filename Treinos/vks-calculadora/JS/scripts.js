const previousOperationText = document.querySelector("#previous-operation");
const currentOperationText = document.querySelector("#current-operation");
const buttons = document.querySelectorAll("#buttons-container button");

class   Calculator {
    constructor(previousOperationText, currentOperationText){
        this.previousOperationText = previousOperationText;
        this.currentOperationText = currentOperationText;
        this.currentOperation = "";
    }

    // adicionando digitos a calculadora
    addDigit(digit){
        console.log(digit);
        //checagem para saber se 1 ponto ja foi adicionado na current
        if(digit === "." && this.currentOperationText.innerText.includes(".")){
            return;
        }

        this.currentOperation = digit;
        this.updateScreen();
    }
    //Processar as operacoes da calculadora
    processOperation(operation){
        //Checar se o valor atual esta vazio para nao fazer operacoes com vazio(ex:5 * vazio)
        if(this.currentOperationText.innerText === "" && operation!== "C"){
            if(this.previousOperationText.innerText !== ""){
                //Muda operacao
                this.changeOperation(operation);
            }
            return;
        }
        //Pegar o valor atual e o valor anterior 
        let operationValue;
        /*Pegar apenas o numero, ou seja, o indice zero do array (numero) deixando a operacao de fora*/
        let previous = +this.previousOperationText.innerText.split(" ")[0];
        let current = +this.currentOperationText.innerText;

        switch(operation) {
        case "+":
            operationValue = previous + current;
            this.updateScreen(operationValue, operation, current, previous);
            break;
        case "-":
            operationValue = previous - current;
            this.updateScreen(operationValue, operation, current, previous);
            break;
        case "/":
            operationValue = previous / current;
            this.updateScreen(operationValue, operation, current, previous);
            break;
        case "*":
            operationValue = previous * current;
            this.updateScreen(operationValue, operation, current, previous);
            break;
        case "DEL":
            this.processDelOperator();
            break;
        case "CE":
            this.processClearCurrentOperation();
            break;
        case "C":
            this.processClearOperation();
            break;
        case "=":
            this.processequalOperator();
            break;
        default:    
            return;
        }
    }

    //Alterar os valores da tela(Atualizacao)
    updateScreen(
        operationValue = null, 
        operation = null, 
        current = null, 
        previous = null 
        ){
        if(operationValue === null){
            this.currentOperationText.innerText += this.currentOperation;
        }else{
            //checar se o valor = 0 se for o previous igual a zero
            if(previous === 0){
                operationValue = current;
            }
            //adicionar valor atual ao antigo
            //Concatena o valor 1 e a operacao a sub linha superior
            this.previousOperationText.innerText = `${operationValue} ${operation}`;
            this.currentOperationText.innerText = "";
        }
    }
    // Alterar a operacao matematica caso seja necessario
    changeOperation(operation){

        const mathOperations = ["*", "/", "+", "-"];
        
        if(!mathOperations.includes(operation)){
            return;
        }
        this.previousOperationText.innerText = this.previousOperationText.innerText.slice(0, -1) + operation;
    }
    //Delete o ultimo digito
    processDelOperator(){
        this.currentOperationText.innerText = this.currentOperationText.innerText.slice(0, -1);
    }
    //Cleana o numero atual;
    processClearCurrentOperation(){
        this.currentOperationText.innerText = "";
    }
    //Clear geral
    processClearOperation(){
        this.currentOperationText.innerText = "";
        this.previousOperationText.innerText = "";
    }
    //Realizar o botao de igual 
   
    processequalOperator() {
        const previous = +this.previousOperationText.innerText.split(" ")[0];
        const current = +this.currentOperationText.innerText;
        const operation = this.previousOperationText.innerText.split(" ")[1];
    
        let result;
        switch (operation) {
            case "+":
                result = previous + current;
                break;
            case "-":
                result = previous - current;
                break;
            case "/":
                result = previous / current;
                break;
            case "*":
                result = previous * current;
                break;
            default:
                return;
        }
        
            // Exibir o cálculo completo no visor
            this.previousOperationText.innerText = `${previous} ${operation} ${current} =`;
            this.currentOperationText.innerText = "";
            primalOperation = 
            // Exibir o resultado abaixo do cálculo completo, com sinal de igual
            this.currentOperationText.innerText = ` ${result}`;
    }

   
    
}

const calc = new Calculator(previousOperationText, currentOperationText);


buttons.forEach((btn)=> {
    btn.addEventListener("click", (e) => {
        const value = e.target.innerText;

        if(+value >= 0 || value === "."){
            calc.addDigit(value);
        } else {
            calc.processOperation(value);
        }
    });
});