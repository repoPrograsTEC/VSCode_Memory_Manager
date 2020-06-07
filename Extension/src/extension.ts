import * as vscode from 'vscode';
import {TreeDataProvider, TreeItem} from './treeview';
import {Data} from './Datos';

//const path = require('path');
//const fs = require('fs');
var ncp = require('ncp').ncp;


//🦄👨‍💻⚡✨🤘🏻⚛️💻🚀🔥 

function copyuDir(){
	let folderPath = vscode.workspace.rootPath;

	ncp.limit = 16;
 
	ncp('/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/LibVSPtr', folderPath, function (err:any) {
 			if (err) {
   				return console.error(err);
 			}
 		console.log('done!');
	});

}

export function activate(context: vscode.ExtensionContext) {

	copyuDir();
	
	let disposable = vscode.commands.registerCommand('extension.play', () => {

		
		vscode.window.showInformationMessage('Hola. Atte: DaniGames 🐛');

		let datos = new Data();
		let newData = new TreeDataProvider();

		datos.showBoxText("🦄¿Desea utilizar servidor remoto? (si / no)🦄");

		vscode.window.registerTreeDataProvider('TreeDataProvider', newData);
		vscode.commands.registerCommand('TreeDataProvider.refreshEntry', () =>{
			newData.data =[];
			newData.refresh();	
		});
		
		
	});

	context.subscriptions.push(disposable);
}

export function deactivate() {}


