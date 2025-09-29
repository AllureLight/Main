const nota = 8;

if(nota >= 9){
    console.log('A');
}else if(nota >= 7){
    console.log('B');
}else{
    console.log('C');
}

switch(true){
    case (nota>= 9):
    console.log('A');
    break;

    case (nota>=7):
    console.log('B');
    break;
}