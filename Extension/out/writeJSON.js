"use strict";
function write(data, name) {
    const fs = require('fs');
    const jsonString = JSON.stringify(data);
    fs.writeFile('./' + name + '.json', jsonString, function (err) {
        if (err) {
            console.log('Error writing file', err);
        }
        else {
            console.log('Successfully wrote file');
        }
    });
}
write({
    name: "Newbie Co.",
    order_count: 0,
    address: "Po Box City",
}, "dani");
//# sourceMappingURL=writeJSON.js.map