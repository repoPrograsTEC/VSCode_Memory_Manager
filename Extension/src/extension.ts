import * as vscode from 'vscode';
import {TreeDataProvider, TreeItem} from './treeview';

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
export function activate(context: vscode.ExtensionContext) {
	
	let folderPath = vscode.workspace.rootPath;
		fs.copyFile('/home/daniel/Desktop/test/asd/VSCode_Memory_Manager/Extension/src/libVSPtr.so', folderPath + '/libVSPtr.so', (err: any) => {
			if (err) {throw err;}
			console.log('File was copied to destination');
		});

		

	let disposable = vscode.commands.registerCommand('extension.play', () => {

		
		vscode.window.showInformationMessage('Hola. Atte: DaniGames 🐛');
						
		//username.show();
 
		let newData = new TreeDataProvider();

		
		vscode.window.registerTreeDataProvider('TreeDataProvider', newData);
		vscode.commands.registerCommand('TreeDataProvider.refreshEntry', () =>{
			
			newData.data =[];
			newData.refresh();
				
		});
		
		

	});

	context.subscriptions.push(disposable);
}

export function deactivate() {}