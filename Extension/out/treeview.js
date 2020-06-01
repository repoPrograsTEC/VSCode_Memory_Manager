"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
class TreeDataProvider {
    constructor() {
        this._onDidChangeTreeData = new vscode.EventEmitter();
        this.onDidChangeTreeData = this._onDidChangeTreeData.event;
        this.data = [];
    }
    addData(element) {
        this.data.push(element);
    }
    getTreeItem(element) {
        return element;
    }
    getChildren(element) {
        if (element === undefined) {
            return this.data;
        }
        return element.children;
    }
    refresh() {
        this._onDidChangeTreeData.fire();
        let folderPath = vscode.workspace.rootPath;
        let path = folderPath + '/cmake-build-debug/List.json';
        let fs = require('fs');
        fs.readFile(path, 'utf8', (err, json) => {
            if (err) {
                console.log("File read failed:", err);
                return;
            }
            let data = JSON.parse(json);
            data.Lista.forEach((element) => {
                this.addData(new TreeItem("ID: " + String(element.ID), [
                    new TreeItem(String("Valor: " + element.Valor)),
                    new TreeItem(String("Tipo de dato: " + element.Tipodedato)),
                    new TreeItem(String("Memoria: " + element.Direccionmemoria)),
                    new TreeItem(String("Referencias: " + element.Referencias))
                ]));
            });
        });
    }
}
exports.TreeDataProvider = TreeDataProvider;
class TreeItem extends vscode.TreeItem {
    constructor(label, children) {
        super(label, children === undefined ? vscode.TreeItemCollapsibleState.None :
            vscode.TreeItemCollapsibleState.Expanded);
        this.children = children;
    }
}
exports.TreeItem = TreeItem;
//# sourceMappingURL=treeview.js.map