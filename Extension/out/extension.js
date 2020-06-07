"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const treeview_1 = require("./treeview");
const Datos_1 = require("./Datos");
//const path = require('path');
//const fs = require('fs');
var ncp = require('ncp').ncp;
//🦄👨‍💻⚡✨🤘🏻⚛️💻🚀🔥 
function copyuDir() {
    let folderPath = vscode.workspace.rootPath;
    ncp.limit = 16;
    ncp('/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/LibVSPtr', folderPath, function (err) {
        if (err) {
            return console.error(err);
        }
        console.log('done!');
    });
}
function activate(context) {
    copyuDir();
    let disposable = vscode.commands.registerCommand('extension.play', () => {
        vscode.window.showInformationMessage('Hola. Atte: DaniGames 🐛');
        let datos = new Datos_1.Data();
        let newData = new treeview_1.TreeDataProvider();
        datos.showBoxText("🦄¿Desea utilizar servidor remoto? (si / no)🦄");
        vscode.window.registerTreeDataProvider('TreeDataProvider', newData);
        vscode.commands.registerCommand('TreeDataProvider.refreshEntry', () => {
            newData.data = [];
            newData.refresh();
        });
    });
    context.subscriptions.push(disposable);
}
exports.activate = activate;
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map