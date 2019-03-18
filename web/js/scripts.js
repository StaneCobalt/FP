
function calculateFunctionPoints(){
    let result = ufp() * tcf();

    document.getElementById("result").innerHTML = result;
}

function tcf(){
    let factors = document.getElementsByName("factor");
    let di = 0.0;
    let size = factors.length;

    for(let i = 0; i < size; i++)
        di += factors[i].value;

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

    for(let i = 0; i < size; i++)
        n += component[i].value;

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

    let costValues = [
        [0.75,0.88,1.00,1.15,1.40,0],       // required software reliability
        [0,0.94,1.00,1.08,1.16,0],          // database size
        [0.70,0.85,1.00,1.15,1.30,1.65],    // product complexity
        [0,0,1.00,1.11,1.30,1.66],          // execution time constraint
        [0,0,1.00,1.06,1.21,1.56],          // main storage constraint
        [0,0.87,1.00,1.15,1.30,0],          // virtual machine volatility
        [0,0.87,1.00,1.07,1.15,0],          // computer turnaround time
        [1.46,1.19,1.00,0.86,0.71,0],       // analyst capabilities
        [1.29,1.13,1.00,0.91,0.82,0],       // applications experience
        [1.42,1.17,1.00,0.86,0.70,0],       // programmer capability
        [1.21,1.10,1.00,0.90,0,0],          // virtual machine experience
        [1.14,1.07,1.00,0.95,0,0],          // programming language experience
        [1.24,1.10,1.00,0.91,0.82,0],       // use of modern programming practices
        [1.24,1.10,1.00,0.91,0.83,0],       // use of software tools
        [1.23,1.08,1.00,1.04,1.10,0]        // required development schedule
    ];

    let costDrivers = 1.0;
    for(let i = 0; i < 15; i++){
        let field = document.getElementsByName("field"+i);
        for(let j = 0; j < field.length; j++){
            if(field[j].checked)
                costDrivers *= costValues[i][field[j].value];
        }
    }

    let result = basic * costDrivers;

    document.getElementById("result").innerHTML = result;
}
