let fs = require('fs');

fs.readFile('/home/daniel/CLionProjects/prueba/cmake-build-debug/List.json', 'utf8', (err, jsonString) => {
		if (err) {
			console.log("File read failed:", err);
			return;
        }
		console.log(jsonString);
    });