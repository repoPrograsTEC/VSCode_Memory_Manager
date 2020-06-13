"use strict";
// Importing 'crypto' module 
const crypto = require('crypto'), 
// Returns the names of supported hash algorithms  
// such as SHA1,MD5 
hash = crypto.getHashes();
// Create hash of SHA1 type 
var x = "hola123";
// 'digest' is the output of hash function containing  
// only hexadecimal digits 
var hashPwd = crypto.createHash('md5').update(x).digest('hex');
console.log(hashPwd);
/*
function validar (contraseña : String){

    const password = "9e107d9d372bb6826bd81d3542a419d6";

    if (contraseña == password){

        return true;
    }
    return false;

}
-*/ 
//# sourceMappingURL=md5.js.map