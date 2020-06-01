"use strict";
const ffi = require("ffi-napi");
//const myLib = require('/home/daniel/Desktop/test/prueba/src/libVSPtr.so');
function Debbug() {
    const mathLibrary = new ffi.Library('/home/daniel/Desktop/test/prueba/src/libVSPtr.so', {
        "Debbug": []
    });
}
/*
function Hola(x:any, y:any){
        

    const mathLibrary = new ffi.Library('/home/daniel/Desktop/test/prueba/src/libuntitled.so',{

        "Sumar":[
                "int", ["int", "int"]
        ],
        "Subtract": [
                "int", ["int", "int"]
        ],
        "Add": [
                "int", ["int", "int"]
        ]

    });

    console.log(mathLibrary.Sumar(x, y));

}


function Pene (x : any){

        console.log(x);
}
*/
module.exports = {
    Debbug: Debbug
};
//# sourceMappingURL=Hola.js.map