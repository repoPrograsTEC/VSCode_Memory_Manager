"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const treeview_1 = require("./treeview");
const path = require('path');
const fs = require('fs');
/*
//input para colocar nombre de usuario
const username = vscode.window.createInputBox();
username.title = "👨‍💻Inserte usuario👨‍💻";
username.onDidAccept(function(){

    vscode.window.showInformationMessage(username.value);
    username.hide();

    });

*/
//🦄👨‍💻⚡✨🤘🏻⚛️💻🚀🔥 
function activate(context) {
    let folderPath = vscode.workspace.rootPath;
    fs.copyFile('/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/libVSPtr.so', folderPath + '/libVSPtr.so', (err) => {
        if (err) {
            throw err;
        }
        console.log('File was copied to destination');
    });
    let disposable = vscode.commands.registerCommand('extension.play', () => {
        vscode.window.showInformationMessage('Hola. Atte: DaniGames 🐛');
        //username.show();
        let newData = new treeview_1.TreeDataProvider();
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