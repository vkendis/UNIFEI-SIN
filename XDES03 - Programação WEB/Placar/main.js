const placar = document.querySelector("#contador")
const bj1 = document.querySelector("#b1")
const bj2 = document.querySelector("#b2")
const reset = document.querySelector("#b3")
const opcoes = document.querySelector("#pontosfinais").value
let placarj1 = 0;
let placarj2 = 0;

bj1.addEventListener("click", () => {
    if ( bj1.style.backgroundColor === 'green' || ( bj2.style.backgroundColor === 'red') ) 
        return 0;

    placarj1++;
    atualizaPlacar();
    Finaliza();
   
});

bj2.addEventListener("click", () => {
    if ( bj1.style.backgroundColor === 'green' )
        return 0;
    placarj2++;
    atualizaPlacar();
    Finaliza();

});

reset.addEventListener("click", () => {
    placarj1 = 0;
    placarj2 = 0;
    atualizaPlacar();
    Finaliza();

})

function atualizaPlacar() {
    placar.textContent = `${placarj1} a ${placarj2}`;
    
}

function Finaliza() {
    let opcoes = parseInt(document.querySelector("#pontosfinais").value); 

    if(placarj1 >= opcoes){
        bj1.style.backgroundColor = 'green'
        bj2.style.backgroundColor = 'red'
    } else if (placarj2 >= opcoes) {
        bj1.style.backgroundColor = 'red'
        bj2.style.backgroundColor = 'green'
    }else {
        bj1.style.backgroundColor = ''
        bj2.style.backgroundColor = ''
    }
}