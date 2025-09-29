const operador = '+';
const a = 10;
const b = 5;

if(operador == '+'){
    console.log(a + b);
}
else if(operador == '+'){
    console.log(a - b);
}
else{
    console.log('Operador Invalido');
}

switch(operador){
    case '+':
    console.log(a + b);
    break;

    case '-':
    console.log(a - b);
    break;

    default:
    console.log('Operador Invalido');
}