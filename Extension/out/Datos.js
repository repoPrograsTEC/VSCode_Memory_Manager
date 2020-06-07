"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
class Data {
    constructor() {
        this.ip = "";
        this.host = "";
        this.password = "";
        this.user = "";
        this.remoto = "";
        this.cont = 1;
    }
    funcion(box) {
        if (this.cont == 1) {
            this.remoto = box.value;
            this.cont++;
            this.asignar();
            box.hide();
        }
        else if (this.cont == 2) {
            this.ip = box.value;
            this.cont++;
            box.hide();
            this.showBoxText("💻Inserte puerto💻");
        }
        else if (this.cont == 3) {
            this.host = box.value;
            this.cont++;
            box.hide();
            this.showBoxText("👨‍Contraseña👨‍");
        }
        else if (this.cont == 4) {
            this.password = box.value;
            this.cont++;
            box.hide();
            this.showBoxText("🚀Inserte usuario🚀");
        }
        else if (this.cont == 5) {
            this.user = box.value;
            this.cont++;
            box.hide();
        }
    }
    showBoxText(title) {
        let box = vscode.window.createInputBox();
        box.title = title;
        let first = this.cont;
        box.onDidAccept(() => this.funcion(box));
        box.show();
    }
    asignar() {
        if (this.remoto == "si" || this.remoto == "Si") {
            this.showBoxText("👨‍💻Inserte IP👨‍💻");
        }
    }
}
exports.Data = Data;
//# sourceMappingURL=Datos.js.map