"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const ffi = require("ffi-napi");
const library = new ffi.Library("/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/LibVSPtr/libVSPtr.so", {
    "TestConection": [
        "int", ["string", "int"]
    ],
    "sendData": [
        "void", ["string", "string"]
    ],
    "recvData": [
        "void", ["string", "string"]
    ]
});
function TestConection(ip, host) {
    library.TestConection(ip, host);
}
exports.TestConection = TestConection;
function sendData(path, user) {
    //"/home/daniel/CLionProjects/prueba/List.json", "Dani"
    library.sendData(path, user);
}
exports.sendData = sendData;
function recvData(path, user) {
    library.recvData("/home/daniel/Desktop/data.json", "Dani");
}
exports.recvData = recvData;
/*

var cliente = new Cliente();
cliente.Hola();
*/
/*

module.exports = {
        Hola: Hola
      };
      */ 
//# sourceMappingURL=Hola.js.map