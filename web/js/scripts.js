
function calculateFunctionPoints(){
    let fp = ufp() * tcf();
    let result = document.getElementById("result");
    result.innerHTML = fp;
}

function tcf(){
    let factors = document.getElementsByName("factor");
    let di = 0.0;
    let size = factors.length;
    for(let i = 0; i < size; i++){
        di += factors[i].value;
    }
    return (0.65 + (0.01 * di));
}

function ufp(){
    let value3Components = document.getElementsByName("three");
    let value4Components = document.getElementsByName("four");
    let value5Components = document.getElementsByName("five");
    let value6Components = document.getElementsByName("six");
    let value7Components = document.getElementsByName("seven");
    let value10Components = document.getElementsByName("ten");
    let value15Components = document.getElementsByName("fifteen");

    let n3 = getComponentNumber(value3Components, value3Components.length);
    let n4 = getComponentNumber(value4Components, value4Components.length);
    let n5 = getComponentNumber(value5Components, value5Components.length);
    let n6 = getComponentNumber(value6Components, value6Components.length);
    let n7 = getComponentNumber(value7Components, value7Components.length);
    let n10 = getComponentNumber(value10Components, value10Components.length);
    let n15 = value15Components[0].value; // there's only 1

    return (n3 * 3.0) + (n4 * 4.0) + (n5 * 5.0) + (n6 * 6.0) + 
        (n7 * 7.0) + (n10 * 10.0) + (n15 * 15.0);
}

function getComponentNumber(component, size){
    let n = 0;
    for(let i = 0; i < size; i++){
        n += component[i].value;
    }
    return n;
}

function calculateBasicCOCOMO(){
    // a and b initialized to organic values
    let a = 2.4;
    let b = 1.05;
    let kdsi = document.getElementById("kdsi").value;
    if(document.getElementById("nominal").checked){
        a = 3.0;
        b = 1.12;
    } else if(document.getElementById("complex").checked){
        a = 3.6;
        b = 1.20;
    }
    let result = (a * Math.pow(kdsi, b));

    document.getElementById("result").innerHTML = result;
}

function calculateIntermediateCOCOMO(){
    // a and b initialized to organic values
    let a = 3.2;
    let b = 1.05;
    let kdsi = document.getElementById("kdsi").value;
    if(document.getElementById("nominal").checked){
        a = 3.0;
        b = 1.12;
    } else if(document.getElementById("complex").checked){
        a = 2.8;
        b = 1.20;
    }
    let basic = (a * Math.pow(kdsi, b));

    return 0;
}
